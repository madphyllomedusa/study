clear;clf;clc;

xmin=0; xmax=1; n=20; X=(xmin:(xmax-xmin)/(n-1):xmax);
c1=3; c2=-2; Y0=c1+c2*X; % "Истинная" функция
% Экспериментальные данные
sigma=0.2; Z=sigma*randn(n,1); Y=Y0+Z;
plot(X,Y0, X,Y,'o'), grid % Контроль
% Явное оценивание:
xm=mean(X); ym=mean(Y);
K=sum((X-xm).*(Y-ym))/(n-1); DX=(std(X)^2);
cn1(2)=K/DX;
cn1(1)=ym-cn1(2)*xm;
Yn1=ym+cn1(2)*(X-xm);
% Непосредственное оценивание средствами MatLab:
cn2=polyfit(X,Y,1)
Yn2=polyval(cn2,X);
% Контроль:
figure(1); plot(X,Y,'*', X,Y0, X,Yn1,'+', X,Yn2,'o'), grid
R=Yn1-Y; sum(R.*Yn1) % Проверка ортогональности
sn=sqrt(sum(R.^2)/(n-2)) % Шумы - сравнить с sigma
tgamma=1.96; delta=tgamma*sn*(((1+(X-xm).^2/DX))/n).^(1/2);
f1=Yn1-delta; f2=Yn1+delta; % (границы)
figure(2); plot(X,Y0, X,Yn1,':', X,f1,'--', X,f2,'--'), grid