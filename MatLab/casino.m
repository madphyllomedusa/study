clc;clear;clf;
%%
tgamma = 1.96;
a = 0;
b = 3;
%%
N = 1e3:1e3:1e5;
for n = N
    u = rand(1,n)* (b-a) + a;
    x = linspace(a,b,n);
    y = f(x);
    integral = integ(a,b,u,n);
    DX =  sum((u - mean(u)) .^ 2)/n;
    delta=(tgamma*sqrt(DX))/sqrt(n);
    real_integral = r_int(a,b);
    f1=integral-delta; f2=integral+delta;
    alpha = log(abs(real_integral-integral))/log(1/n);
end

plot(N,f1,'ok',N,f2,'ok',N,integral,'om',N,real_integral,'or')
%%
function func = f(x)
    func = sin(x);
end

function integral = integ(a,b,u,n)
    integral = ((b-a)/n) * sum(f(u));
end

function real_integral = r_int(a,b)
    real_integral = cos(a)-cos(b);
end
