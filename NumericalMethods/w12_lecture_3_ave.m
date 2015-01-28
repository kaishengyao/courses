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
rlz = 20;
ave = zeros(1,n);
for j = 1:rlz
    utn(j,:) = ut + noise * (randn(1,n) + i * randn(1,n));
    ave = ave + utn(j,:);
end
un = ifft(ave);
figure(1), subplot(2,1,1), plot(t, abs(un), 'k'); hold on;
close all;
slice=[0:0.5:10];
[T,S] = meshgrid(t,slice);
[K,S] = meshgrid(k,slice);

f = 0;
U = sech(T - 10 *sin(S)).*exp(i * f * T);
figure(2);
subplot(2,1,1)
waterfall(T,S,U), colormap([0,0,0]), view(-15,70);

for j = 1:length(slice)
    Ut(j,:) = fft(U(j,:));
    Kp(j,:) = fftshift(K(j,:));
    Utp(j,:) = fftshift(Ut(j,:));
    Utn(j,:) = Ut(j,:) + noise* (randn(1,n) + i * randn(1,n));
    Utnp(j,:) = fftshift(Utn(j,:));
    Un(j,:) = ifft(Utn(j,:));
end

figure(2);
subplot(2,1,2)
waterfall(Kp, S, abs(Utp)/max(abs(Utp(1,:))));
colormap([0,0,0]);
view(-15,70);

figure(3);
subplot(2,1,2)
waterfall(Kp, S, abs(Utnp)/max(abs(Utnp(1,:))));
colormap([0,0,0]);
view(-15,70);

% averaging
close(figure(3))
ave = zeros(1,n);
for j = 1:length(slice)
    ave = ave + Utn(j,:); 
end
ave = ave / length(slice);
figure(4);
subplot(2,1,2)
plot(fftshift(k), abs(fftshift(ave))/max(abs(fftshift(ave))));
colormap([0,0,0]);

filter = exp(-0.2*(k).^2);
for j = 1:length(slice)
    Utnf(j,:) = filter .* Utn(j,:);
    Unf(j,:) = abs(ifft(Utnf(j,:)));
end

figure(4);
subplot(2,1,2)
waterfall(T, S, Unf);
colormap([0,0,0]);
view(-15,70);


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