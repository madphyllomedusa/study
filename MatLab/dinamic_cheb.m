clc;clf;
clear;
n = 51;
dev = [];



for i = 1:n
    cheb_roots = Chebishev(i);
    zxc = polyfit([-1,1],[0,5],1);
    x = polyval(zxc,cheb_roots);
    y = sin(x);
    lag = Lagrange(x,y,i-1);
    t = min(x):0.001:max(x);
    g = polyval(lag,t);
    dev = [dev,max(abs(g-sin(t)))];
end
plot(2:n,dev,'o-m');

mx = -1;
ind = 0;
L = Lagrange(x,y,n);
for i = min(x):(max(x)-min(x))/1000:max(x)
    if abs(polyval(L,i) - sin(i)) > mx
        mx = abs(polyval(L,i) - sin(i));
        ind = i;
    end
end
mx


function Ch = Chebishev(n)
    Tn_2 = [0,1];
    Tn_1 = [1,0];
    Tn_1_x2 = 0;
    Tn = [0,0];
    
    for i = 1:n-1
        Tn_1_x2 = conv(Tn_1,[2,0]);
        if i > 1
            Tn_2= conv(Tn_2,[0,1]);
        end
        Tn_2 = conv(Tn_2,[0,1]);
        Tn = Tn_1_x2 - Tn_2;
        Tn_2 = Tn_1;
        Tn_1 = Tn;
    end
    T_norm = 1/(2^(n-1))*Tn;
    Ch = transpose(roots(T_norm));
end

function L = Lagrange(x,y,n)
    L = zeros([1,n]);
    for i = 1:n
        A = 1;
        for j = 1:n
            if j ~= i
                A = conv(A,[1/(x(i) - x(j)), -x(j)/(x(i) - x(j))]);
            end
        end
    L = L + y(i)*A;
    end
end