clear;clc;
%Help
x0 = 0.5;                 % Начальная точка
eps = 0.0000001;
temp = 1;
k = 0;

%Plot
z = 0:0.01:1;
y1 = x0;
%y2 = z - cos(z);
y2 = cos(z) - z.^3;

xline(0);
hold all;
yline(0);
xline(x0,':b');
plot(z,y2,'-r');
grid on;

%Newton
if (df(x0) ~= 0)
    while (temp>eps) 
            k=k+1;
            plot(x0,f(x0),'ok')
            y3 = f(x0) + df(x0)*(z-x0);
            plot(z,y3,':b');
            x1 = x0 - (f(x0)/df(x0));
            fprintf('x%d = %.10f\n',k,x1);
            temp = abs(x1-x0);
            x0 = x1;
            x_root = x1;
    end
else 
    disp('Необходимое условие не выполнено');
end

alp = 1;
x0 = 0.5;
temp = 1;

if (df(x0) ~= 0)
    while (temp>eps) 
            x1 = x0 - (f(x0)/df(x0));
            temp = abs(x1-x0);
            alp = log(abs(x1 - x_root))/log(abs(x0-x_root));
            fprintf('alpha = %.4f\n',alp);
            x0 = x1;
    end
end

function f = f(x)            % Объявляем функции
%f = x - cos(x);
f = cos(x) - x.^3;

end

function df = df(x)
%df = sin(x) + 1;
df = - sin(x) - 3*x.^2;
end