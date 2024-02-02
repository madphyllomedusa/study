clc
clear 

a=1;
b=3;
n= 20000 

h=(b-a)/n;

x=[a:h:b];
y=@(x)sin(x);
sum=0;

real = integral(y,a,b)
sum = 0;
div_arr = size(1,n);

alpha_arr = size(1,n);

for i = 18000:n %увеличиваем число отрезков
    h1=(b-a)/i; %шаг отрезка
    x1=(a:h1:b);

    k = i+1; %на сколько отрезков делим

    Simp = 0;
    for i=2:k
        Simp = Simp + h1*(y(x1(i-1))+4*sin(x1(i-1)+h1/2)+y(x1(i)))/6;
    end

    integral(y,a,b);
    
    div_arr = abs(integral(y,a,b) - Simp);
    
Simp= 0;

alpha_arr(i) = log(div_arr)/log(h1);
end

grid on
hold all

size(alpha_arr)

n_arr = linspace(18000,n,2001);
size(n_arr)
plot(n_arr,alpha_arr(18000:n),'-r')
