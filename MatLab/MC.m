clc
clear 
format long 

y = @(x) sin(x);

a = 0;
b = 1;
n = 10000;
m = 1.4*max(linspace(a,b));

for i = 1:n
    x_val = rand(1)*(b-a) + a;
    y_val = rand(1)*m;
    
    fx = y(x_val);
    
    if y_val < fx
        under(i,1) = x_val;
        under(i,2) = y_val;
    else
        above(i,1) = x_val;
        above(i,2) = y_val;

    end
end

under2(:,1) = nonzeros(under(:,1));
under2(:,2) = nonzeros(under(:,2));
above2(:,1) = nonzeros(above(:,1));
above2(:,2) = nonzeros(above(:,2));

plot(above2(:,1),above2(:,2),'r.');
hold all
grid on
plot(under2(:,1),under2(:,2),'b.');
x=a:1/n:b;
f = y(x);
plot(x,f,'k','LineWidth',2)
MC = length(under2)/n*(m*(b-a))
