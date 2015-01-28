function w12_lecture_1_fft_sech
% winter 12 lecture on fft
clear all; close all; clc;

L = 30;
n = 512;

t2 = linspace(-L/2, L/2, n+1); t = t2(1:n);
k  = (2*pi/L) * [0:(n/2-1) (-n/2):-1] ;
u = sech(t); %signal, need coherent frequency components to generate signals
% noise by definition doesn't have coherent frequency components
figure(1), subplot(3,1,1), plot(t, u, 'k'); hold on;

ut = fft(u); 

% add noise to frequency domain to simulate white noise
noise = 20;
utn = ut + noise * (randn(1,n) + i * randn(1,n));
un = ifft(utn);
figure(1), subplot(3,1,2), plot(t, abs(un), 'k'); hold on;
figure(1), subplot(3,1,3), plot(fftshift(k), abs(fftshift(utn))/max(abs(fftshift(utn))), 'k')
axis([-2*pi/L*n/2, 2*pi/L*n/2, 0, 1])
xlabel('wavenumber (k)')
ylabel('|ut|/max(|ut|)')

filter = exp(-0.2*(k).^2);
unft = filter .* utn;
unf = ifft(unft);

figure(2), subplot(3,1,1), plot(t, abs(un), 'k'); hold on;
figure(2), subplot(3,1,2), plot(t, abs(unf), 'k'); hold on;

% filter at other frequency position 
filter = exp(-0.2*(k+10).^2);
unft = filter .* utn;
unf = ifft(unft);
figure(2), subplot(3,1,3), plot(t, abs(unf), 'k');hold on;

% shaper filter
filter = exp(-0.1*(k).^2);
unft = filter .* utn;
unf = ifft(unft);

figure(3), subplot(3,1,1), plot(t, abs(un), 'k'); hold on;
figure(2), subplot(3,1,2), plot(t, abs(unf), 'r'); hold on;

% filter at other frequency position 
filter = exp(-0.1*(k+10).^2);
unft = filter .* utn;
unf = ifft(unft);
figure(2), subplot(3,1,3), plot(t, abs(unf), 'r'); hold on;

% even shaper filter
filter = exp(-0.01*(k).^2);
unft = filter .* utn;
unf = ifft(unft);

figure(2), subplot(3,1,2), plot(t, abs(unf), 'g'); hold on;

% filter at other frequency position 
filter = exp(-0.01*(k+10).^2);
unft = filter .* utn;
unf = ifft(unft);
figure(2), subplot(3,1,3), plot(t, abs(unf), 'g'); hold on;

% change filter shape
filter = sech(-0.01*(k).^2);
unft = filter .* utn;
unf = ifft(unft);

figure(2), subplot(3,1,2), plot(t, abs(unf), 'b'); hold on;

% filter at other frequency position 
filter = exp(-0.1*(k+10).^2);
unft = filter .* utn;
unf = ifft(unft);
figure(2), subplot(3,1,3), plot(t, abs(unf), 'b'); hold on;


end