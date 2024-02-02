clc
clear 
format long 

a=0;
b=1;
n=100; 

h=(b-a)/n;

x=[a:h:b];
y=@(x)sin(x);
sum=0;

real = integral(y,a,b)





for i=1:n-1
    sum = sum + y(x(i))*h;
end
left_rect = sum

h1=(b-a)/2/n;
x1=[a:h1:b];
sum1= 0;

for i=1:2*n-1
    sum1 = sum1 + y(x1(i))*h1;
end
left_rect1 = sum1

Runge = abs(left_rect-left_rect1)

Richardson = (2.^2*left_rect1-left_rect)/(2.^2-1)

