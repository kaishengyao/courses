close all;

Img = imread('c:\Users\kaisheny\Pictures\withclassmatesontopofyujiashan.jpg', 'JPEG');

imshow(Img);
Imgd = double(Img);
[nrow, ncol] = size(Imgd);
Imbw = rgb2gray(Img); 
pcolor(Imbw); shading interp;
Imgbw = Imbw([nrow:-1:1],:);
pcolor(Imgbw); shading interp;

Imgdbw = double(Imbw);
Imgdbw = Imgdbw([nrow:-1:1],:);
pcolor(uint8(Imgdbw)); shading interp; colormap(hot);
Imgdbwr = uint8(Imgdbw);
