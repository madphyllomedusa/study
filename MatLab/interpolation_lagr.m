clear; clc ; % очистка пам€ти и результатов

n=8  ;   % число узлов
m=n-1 ;      % степень интерпол€ционного полинома

%=====¬ввод узлов и узловых значений==========
x=[-1;0;1;6;7;8;9;10];
y=[-1;2;3;2;6;5;6;5];
polyfit(x,y,7)
%вычисление интерпол€ционного полинома Ћагранжа
N=101 ; h=(x(n)-x(1))/(N-1) ;
 for k=1:N
     Z(k)=0 ; 
     X(k)=x(1)+h*(k-1) ;
    % Y(k)=fun(X(k)) ;
     for i=1:n
         P=1 ;
         for j=1:n
             if j~=i 
                P=P*(X(k)-x(j))/(x(i)-x(j));
             end
         end
         Z(k)=Z(k)+y(i)*P ;
     end
 end

f(x,y)

%============ графики ========================
plot(x,y,'*b',X,Z,'-r','LineWidth',2.5) 
grid % нанести координатную сетку 

function A = f(x, y)
 
    sz = size(x);
    A = zeros([sz(1), sz(2) + 1]);
    sz = sz(2);
 
    for k = 1:1:sz
        f = [0, 1];
        for i = 1:1:sz
            if i ~= k
                f = conv(f, [1/(x(k) - x(i)), -x(i)/(x(k) - x(i))]);
            end
        end
        tmp = size(f);
        tmp = tmp(2);
 
        if sz - tmp > 0
            f = cat(2, zeros([1, sz - tmp]), f);
        end
        [A; f]
        A = A + f * y(k);
 
    end
end