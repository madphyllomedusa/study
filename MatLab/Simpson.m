clc
clear 
format long 

y = @(x) sin(x);

a = 0;
b = 1;
n = 10;

h = (b-a)/n;

x = linspace(a,b,2*n+1);
real = integral(y,a,b)
sum1 = sum(y(x(2:2:end-1)));
sum2 = sum(y(x(3:2:end-2)));

Simpson = (b-a)*(y(a) + 4*sum1 + 2*sum2 + y(b))/(3*2*n)

x1 = linspace(a,b,4*n+1);
sum11 = sum(y(x1(2:2:end-1)));
sum22 = sum(y(x1(3:2:end-2)));

Simpson1 = (b-a)*(y(a) + 4*sum11 + 2*sum22 + y(b))/(3*4*n)
Runge = abs(Simpson-Simpson1)/15

Richardson = (2.^4*Simpson1-Simpson)/(2.^4-1)

alpha = log(abs(real-Simpson))/log(h)
