% for hw1
clear all; close all; clc; 
load Testdata

L=15; % spatial domain 
n=64; % Fourier modes 
x2=linspace(-L,L,n+1); x=x2(1:n); y=x; z=x; 
k=(2*pi/(2*L))*[0:(n/2-1) -n/2:-1]; ks=fftshift(k); 

[X,Y,Z]=meshgrid(x,y,z); 
[Kx,Ky,Kz]=meshgrid(ks,ks,ks); 

avet=zeros(n,n,n);
for j=1:20 
Un(:,:,:)= reshape(Undata(j,:),n,n,n); 
Unt = fftn(Un);
avet = avet + Unt; 
end 
close all;
figure(1); 
isosurface(X,Y,Z,abs(Un),0.4) 
axis([-20 20 -20 20 -20 20]), grid on, drawnow 
figure(2);
avet2 = avet ./ max(max(max(abs(avet))));
close all; isosurface(Kx,Ky,Kz,abs(fftshift(avet2)),0.83) 
view(-15,70);

% get the frequency signature
[b,a,c] = ind2sub(size(avet2), find(abs(avet2)== max(abs(avet2(:)))));
kmax = [k(a),k(b),k(c)];

% the average position
kspatial = 2 * L/(2*pi) * kmax; 

% find resolution
for r=0.1:0.1:4.0,
    filterX = 1/sqrt(2*pi * r) * exp(-r*(k - k(a)).^2/(2 * r));
    filterY = 1/sqrt(2*pi * r) * exp(-r*(k - k(b)).^2/(2 * r));
    filterZ = 1/sqrt(2*pi * r) * exp(-r*(k - k(c)).^2/(2 * r));
    [Fx,Fy,Fz] = meshgrid(filterX, filterY, filterZ);

    Ave2f = ((ave2 .* Fx) .* Fy) .* Fz;
    close all; isosurface(Kx,Ky,Kz,abs(fftshift(Ave2f))); 
    ts = sprintf('r = %f', r);
    title (ts);
    view(-15,70);
    pause(1);
end

r = 4.0;
filterX = 1/sqrt(2*pi * r) * exp(-r*(k - k(a)).^2/(2 * r));
filterY = 1/sqrt(2*pi * r) * exp(-r*(k - k(b)).^2/(2 * r));
filterZ = 1/sqrt(2*pi * r) * exp(-r*(k - k(c)).^2/(2 * r));
[Fx,Fy,Fz] = meshgrid(filterX, filterY, filterZ);

for j=1:20 
Un(:,:,:)= reshape(Undata(j,:),n,n,n); 
Unt = fftn(Un);
Untf = ((Unt .* Fx) .* Fy) .* Fz;
Untfi = ifftn(Untf);
Untfij(j,:,:,:) = Untfi;
[b,a,c] = ind2sub(size(Untfi), find(abs(Untfi) == max(abs(Untfi(:)))));
px(j) = x(a);  
py(j) = y(b);  
pz(j) = z(c);

end

close all;
plot3(px, py, pz);
hold on;
plot3(px(20),py(20),pz(20),'rx','MarkerSize',50,'LineWidth',4);
[px(20), py(20), pz(20)]
    
