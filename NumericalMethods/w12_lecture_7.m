% winter 12 lecture on fft
clear all; close all; clc;

L = 30;
n = 512;

t2 = linspace(-L/2, L/2, n+1); t = t2(1:n);
k  = (2*pi/L) * [0:(n/2-1) (-n/2):-1] ;
ks = fftshift(k);
u = sech(t); %signal, need coherent frequency components to generate signals
u = u + cos(0.2 * t);
u = u + cos(20 * t);
slices=[0:0.1:10];
spec = [];

width = 1; 
slides=0:0.1:10;
figure(2);
for j=1:length(slides)
    f = exp(-width * (t- slides(j)).^2);
    uf = u .* f; 
    uft = fft(uf);
    
    subplot(3,1,1); plot(t, u, 'k', t, f, 'm');
    subplot(3,1,2); plot(t, uf, 'k');
    subplot(3,1,3); plot(ks, abs(fftshift(uft))./max(abs(fftshift(uft))));
    axis([-60 60 0 1]);
    drawnow;
    pause(0.1); 
    spec = [spec; abs(fftshift(uft))];
end

figure(2);
pcolor(slides, ks, spec.'); shading interp;
colormap(hot);

