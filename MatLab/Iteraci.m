clear;clc;
%Help
x0 = 0.8;               % Начальное значение
eps = 0.001;            % Точность
k = 0;                  % Счётчик
temp = 1;
alp = 1;
%plots
z = -5:0.01:5;
y1 = z;
%y2 = cos(z);
%y2 = exp(-(z)/2);
y2 = nthroot(cos(z),3);
%y2 = cos(z).^(1/3);
plot(y1,z,'-m');
xline(0);
hold all;
yline(0);
grid on;
plot(z,y2,'-r');
if (abs(df(x0))<=1)
    while (temp>eps) 
        k=k+1;
        plot(x0,phi(x0),'ok')
        x1 = phi(x0);
        %lambda = abs((phi(x1)-phi(x0))/(x1-x0));
        fprintf('x%d = %.5f\n',k,x1);
        %fprintf('lambda %.5f\n',lambda);
        temp = abs(x1-x0);
        temp2 = x0;
        x0 = x1;
        x_root = x1;
    end
else 
    disp('Необходимое условие не выполнено')
end

temp = 1;
k = 0;
x0 = 0.8;
%lambda = abs((phi(x_root)-phi(x0))/(x_root-x0));
%fprintf('\nlambda %.5f\n',lambda);
if (abs(df(x0))<=1)
    while (temp>eps)
        x1 = phi(x0);
        temp = abs(x1-x0);
        alp = log(abs(x1 - x_root))/log(abs(x0-x_root));
        fprintf('alpha = %.4f\n',alp);
        x0 = x1;
    end
end

function phi = phi(x)         % Объявляем функцию phi(x)
%phi = cos(x);
%phi = exp(-(x)/2);
phi= nthroot(cos(x),3);
end

function df = df(x)
%df = -sin(x);
%df = -exp(-x/2)/2;
df = -(sin(x)*nthroot(cos(x), 3))/(3*cos(x));
end
