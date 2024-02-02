clc
clear 
format long 
grid on
hold all

a=0;
b=5;
n=1;  



x_build=(a:0.001:b);
y_build = sin(x_build);
plot(x_build,y_build,'r-')
 
plot([a b],[0 0],'b-');


for i=1:15
    h=(b-a)/n;
    x=[a:h:b];
    y = sin(x);
    q = plot(x,y,'b-');
    h = h/2;
    n = n+1
    pause;
    delete(q);
end

