    clc
clear 

a=0;
b=1;
n=10000; 

h=(b-a)/n;

x=[a:h:b];
y=@(x)sin(x);
real = integral(y,a,b)

sum=0;
% for i=0:n-1
%     temp = a + (i+0.5)*h;
%     sum = sum + y(temp);
% end
% 
% middle_rect = sum*h

for i=1:n-1
    sum = sum + y((x(i)+x(i+1))/2)*h;
end

middle_rect = sum

h1=(b-a)/2/n;
x1=[a:h1:b];
sum1= 0;

for i=1:2*n-1
    sum1 = sum1 + y((x1(i)+x1(i+1))/2)*h1;
end
middle_rect1 = sum1

Runge = abs(middle_rect-middle_rect1)/3

Richardson = (2.^2*middle_rect1-middle_rect)/(2.^2-1)

