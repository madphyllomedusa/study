clc
clear 


a = 0;
b = 1;
n = 1000;
h = (b-a)/n;

x=[a:h:b];
y = @(x) sin(x);

real = integral(y,a,b)



temp = 0;
for i = 1:n-1
%     x0 = a + (i-1)*h;
%     x1 = a + i*h;
    temp = temp + (y(x(i)) + y(x(i+1)))*h/2;
end

trapezoid = temp

h1=(b-a)/2/n;
x1=[a:h1:b];
temp1 = 0;

for i=1:2*n
%     x0_1 = a+(i-1)*h1;
%     x1_1 = a+i*h1;
    temp1 = temp1 + (y(x1(i)) + y(x1(i+1)))*h1/2;
end
trapezoid1 = temp1

Runge = abs(trapezoid-trapezoid1)/3

Richardson = (2.^2*trapezoid1-trapezoid)/(2.^2-1)

alpha = log(abs(real-trapezoid))/log(h)

