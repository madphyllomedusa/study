clc;clear;clf; 
hold all; grid on;
%% 
x = 0:0.1:5;
n = length(x);
h = x(2) - x(1);
y = f(x);
diffY = fDiff(x);    
plot(x,diffY,'--k') 
%%
for i = 2:n         
   I_1(i) = (y(i) - y(i-1))/h;  
end
 
for i = 2:n-1
    dev_I_1(i) = abs(diffY(i) - I_1(i+1));  
end 

alpha_I_1 = log(max(dev_I_1))/log(h)
C_I_1 =  max(dev_I_1)/(h.^1)

x_I_1 = x(2):h:x(n);
for i = 1:n-1
   I_1_help(i) = I_1(i+1);  
end

q = plot(x_I_1-h,I_1_help,'-r');
input('');
delete(q); 

 
%%
for i = 1:n-1        
   I_2(i) = (y(i+1) - y(i))/h;  
end
 
for i = 1:n-2
    dev_I_2(i) = abs(diffY(i) - I_2(i));  
end

alpha_I_2 = log(max(dev_I_2))/log(h) 
C_I_2 =  max(dev_I_2)/(h.^1)
x_I_2 = x(1):h:x(n-1);

q = plot(x_I_2,I_2,'-b');
input('');
delete(q);


%%
for i = 2:n-1        
   II_1(i) = (y(i+1) - y(i-1))/(2*h);  
end
 
for i = 2:n-2
    dev_II_1(i) = abs(diffY(i) - II_1(i));  
end

for i = 2:n-1
   II_1_help(i-1) = II_1(i); 
end

alpha_II_1 = log(max(dev_II_1))/log(h)
C_II_1 =  max(dev_II_1)/(h.^2)

x_II_1 = x(2):h:x(n-1);
q = plot(x_II_1,II_1_help,'-m');
input('');
delete(q);
%%
for i = 1:n-2      
   II_2(i) = (4*y(i+1) - 3*y(i) -y(i+2))/(2*h);  
end
 
for i = 1:n-2
    dev_II_2(i) = abs(diffY(i) - II_2(i));  
end
for i = 2:n-2
   II_2_help(i-1) = II_2(i);  
end

alpha_II_2 = log(max(dev_II_2))/log(h) 
C_II_2 =  max(dev_II_2)/(h.^2)

x_II_2 = x(2):h:x(n-2);
q = plot(x_II_2,II_2_help,'-g');
input('');
delete(q);
%%
for i = 3:n-2      
   IV_1(i) = (y(i-2) - 8*y(i-1) +8*y(i+1) - y(i+2))/(12*h);  
end
 
for i = 3:n-2
    dev_IV_1(i) = abs(diffY(i) - IV_1(i)); 
end
for i = 3:n-2
   IV_1_help(i-2) = IV_1(i);  
end

alpha_IV_1 = log(max(dev_IV_1))/log(h) 
C_IV_1 =  max(dev_IV_1)/(h.^4)

x_IV_1 = x(3):h:x(n-2);
q = plot(x_IV_1,IV_1_help,'-b');
input('');
delete(q);
%%
for i = 2:n-3      
   IV_2(i) = (-3*y(i-1) - 10*y(i) + 18*y(i+1)-6*y(i+2) + y(i+3))/(12*h);  
end
 
for i = 2:n-3
    dev_IV_2(i) = abs(diffY(i) - IV_2(i));  
end

for i = 2:n-3
   IV_2_help(i-1) = IV_2(i);  
end

alpha_IV_2 = log(max(dev_IV_2))/log(h)
C_IV_2 =  max(dev_IV_2)/(h.^4)

x_IV_2 = x(2):h:x(n-3);
q = plot(x_IV_2,IV_2_help,'-b');
input('');
delete(q); 

%%
function func = f(x)
    func = sin(x);
end

function funcDiff = fDiff(x)
    funcDiff = cos(x);
end