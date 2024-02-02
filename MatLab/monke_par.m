clc;clf;clear;
warning('off','all');
hold all
grid on
%%
x = 0:0.1:2;
a = 2; b = -4; c = 2;
y = a*x.^2 + b*x +c;
n = length(x);
sigma = 0.3;
u = randn(1,n);
y_rand = sigma .* u +y;

%%
sum_x = sum(x);
sum_x_sq = sum(x.^2);
sum_x_th = sum(x.^3);
sum_x_fh = sum(x.^4);
sum_y = sum(y_rand);
sum_xy = sum(x.*y_rand);
sum_sqx_y = sum(x.^2.*y_rand);

A = [n, sum_x, sum_x_sq;
    sum_x, sum_x_sq, sum_x_th;
    sum_x_sq, sum_x_th, sum_x_fh];
B = [sum_y; sum_xy; sum_sqx_y];

coeffs= inv(A)*B;
a = coeffs(3);
b = coeffs(2);
c = coeffs(1);

y_values = a * x.^2 + b * x + c;
%%
r = y_rand-y_values;
check = abs(sum(r.*y_values));
sn = sqrt(sum(r.^2)/(n-3));
trustFunc = tf(x,y_values,n,sn);
%%
plot(x, y_values,'-b');
plot(x,y_rand,'.k');
plot(x,y,'--r');
%%
fprintf('Результат скалярного произведения векторов подгонки и невязок = %.10f\n',check);
fprintf('Сигма = %.4f\n',sigma);
fprintf('Уровень шумов = %.4f\n',sn);
%%
function trustFunc = tf(x,y,n,sn)
    trustX = mean(x);
    trustY = mean(y);
    K = sum((x-trustX).*(y-trustY))/(n-1);
    DX = (std(x)^2);
    c = K/DX;
    tgamma=3.291; delta=tgamma*sn*(((1+(x-trustX).^2/DX))/n).^(1/2);
    trustFunc = y + c*(x-trustX)+c*(x-trustX).^2;
    f1=trustFunc-delta; f2=trustFunc+delta;
    plot(x,f1,'--k',x,f2,'--k')
end