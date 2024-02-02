clc;clear;clf;
hold all;grid on;
%%
x_change = [];
y_change = [];
h1 = 0.001;
%%
while h1 > 0.00001
    H = h1:-h1/10:h1/10;
    for h = H
        n = 30;
        X = 0:h:h*(n-1) ;
        n = size(X,2) ;
        Y = sin (X);
        dY = cos (X) ;
        
        I4= [];
        for j = 3:n-2
            I4 = [I4,(Y(j-2) - 8*Y(j-1) + 8*Y(j+1) - Y(j+2))/(12*h)];
        end
        alphaI4 = log(max(abs(dY(3:n-2) - I4)))/log(h);
        x_change = [h, x_change];
        y_change = [max(abs(dY(3:n-2) - I4)), y_change];
        fprintf('Шаг = %.6f\n',h);
        q = plot(x_change,y_change,'-r');
        input('');
        delete(q);
    end
    h1 = h1/10;
end
%%
plot(x_change,y_change,'-r');