P = [1 ,-1];
for i = 2:20
    P = conv(P,[1,-i]);
end
P(2)= P(2)+10^(-6);
roots(P);

x = 0:0.1:2*pi;
y1 = sqrt(-(x - pi).^2 + pi^2);
%x1 = pi-0.5:0.1:pi+0.5;
%y2 = -pi^(2/3)*(x1.^2) - 2 * (pi^(1/3)) * x1 + 1;
y = sin(x);
z = 0:0.1:2*pi;
c = -sin(z);
plot(x,y, '-ms');
    hold on
plot (z,c,'-ms');
plot (pi/2,0,'ro');
plot (3*pi/2,0,'ro');
plot(x, y1);
plot(x, -y1);
plot(x1,-2);
