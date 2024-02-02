function interpolation_new
%xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
clear; clc ; % ������� ������ � �����������

n=8  ;   % ����� �����
m=n-1 ;      % ������� ����������������� ��������

%=====����� ����� � ������� ��������==========
x=[-1;0;1;6;7;8;9;10];
y=[-1;2;3;2;6;5;6;5];

%���������� ����������������� �������� ��������
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

%============ ������� ========================
plot(x,y,'*b',X,Z,'-r','LineWidth',2.5) 
grid % ������� ������������ ����� 