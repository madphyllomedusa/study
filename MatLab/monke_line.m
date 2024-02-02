clc;clf;clear;
warning('off','all');
hold all
grid on
%%
x = 0:0.1:2;
k = 1;b = 0;
y = k * x + b;
n = length(x);
sigma = 0.1;
u = randn(1,n);
y_rand = sigma .* u +y;
%%
sum_x_sq = sum(x.^2);
sum_x = sum(x);
sum_y = sum(y_rand);
sum_xy = sum(x.* y_rand);

A = [sum_x_sq, sum_x; sum_x, n];
B = [sum_xy;sum_y];

coeffs= inv(A)*B;
a = coeffs(1);
b = coeffs(2);
y_values = a * x + b;
%%
r = y_rand-y_values;
check = abs(sum(r.*y_values));
sn = sqrt(sum(r.^2)/(n-2));
trustFunc = tf(x,y_values,n,sn);
%%
plot(x, y_values,'-b');
plot(x,y_rand,'.k');
plot(x,y,'--r');
%%
fprintf('Результат скалярного произведения векторов подгонки и невязок = %.10f\n',check);
fprintf('®',sigma);
fprintf('Уровень шумов = %.4f\n',sn);
%%
function trustFunc = tf(x,y,n,sn)
    trustX = mean(x);
    trustY = mean(y);
    K = sum((x-trustX).*(y-trustY))/(n-1);
    DX = (std(x)^2);
    a = K/DX;
    tgamma=3.291; delta=tgamma*sn*(((1+(x-trustX).^2/DX))/n).^(1/2);
    trustFunc = trustY+a*(x-trustX);
    f1=trustFunc-delta; f2=trustFunc+delta;
    plot(x,f1,'--k',x,f2,'--k')
end
