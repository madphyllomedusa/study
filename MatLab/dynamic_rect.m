clc
clear 
format long 
grid on
hold all

a=0;
b=5;
n=10; 

x_build=(a:0.001:b);
y_build = sin(x_build);

k = 6

for i = 1:k
    plot(x_build,y_build,'r-')
    plot([a b],[0 0],'b-');
    for i=1:n 
     h=(b-a)/n;
     x=[a:h:b];
  
     y(i) = sin(x(i));
    
        q = plot([x(i) x(i+1)],[sin(x(i)) sin(x(i))],'b-');
     if y(i) > 0
            w =  plot([x(i) x(i)],[sin(x(i)) 0],'b--');
             w = plot([x(i) x(i)],[sin(x(i-1)) 0],'b--');
     end
     if y(i) < 0
            w = plot([x(i) x(i)],[sin(x(i)) 0],'b--');
           w = plot([x(i) x(i)],[sin(x(i-1)) sin(x(i))],'b--');
     end
    end
   n = 2*n;
   pause;
   cla;
end
