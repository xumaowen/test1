clear all;
clc;
sub052=importdata('R-ATR/sub-052_right-fiber-ATR_fa__Clean.txt');
sub052_tensor=sub052(2825:9069,:);
sub083=importdata('R-ATR/sub-083_right-fiber-ATR_fa__Clean.txt');
sub083_tensor=sub083(2825:9069,:);
sub328=importdata('R-ATR/sub-328_right-fiber-ATR_fa__Clean.txt');
sub328_tensor=sub328(2825:9069,:);
sub329=importdata('R-ATR/sub-329_right-fiber-ATR_fa__Clean.txt');
sub329_tensor=sub329(2825:9069,:);
sub354=importdata('R-ATR/sub-354_right-fiber-ATR_fa__Clean.txt');
sub354_tensor=sub354(2825:9069,:);
sub383=importdata('R-ATR/sub-383_right-fiber-ATR_fa__Clean.txt');
sub383_tensor=sub383(2825:9069,:);
sub386=importdata('R-ATR/sub-386_right-fiber-ATR_fa__Clean.txt');
sub386_tensor=sub386(2825:9069,:);
sub396=importdata('R-ATR/sub-396_right-fiber-ATR_fa__Clean.txt');
sub396_tensor=sub396(2825:9069,:);
sub438=importdata('R-ATR/sub-438_right-fiber-ATR_fa__Clean.txt');
sub438_tensor=sub438(2825:9069,:);
sub439=importdata('R-ATR/sub-439_right-fiber-ATR_fa__Clean.txt');
sub439_tensor=sub439(2825:9069,:);
template=importdata('R-ATR/template_right-fiber-ATR_fa__Clean.txt');
template_tensor=template(2825:9069,:);
mse052=mean((sub052_tensor(:)-template_tensor(:)).^2);
mse083=mean((sub083_tensor(:)-template_tensor(:)).^2);
mse328=mean((sub328_tensor(:)-template_tensor(:)).^2);
mse329=mean((sub329_tensor(:)-template_tensor(:)).^2);
mse354=mean((sub383_tensor(:)-template_tensor(:)).^2);
mse383=mean((sub383_tensor(:)-template_tensor(:)).^2);
mse386=mean((sub386_tensor(:)-template_tensor(:)).^2);
mse396=mean((sub396_tensor(:)-template_tensor(:)).^2);
mse438=mean((sub438_tensor(:)-template_tensor(:)).^2);
mse439=mean((sub439_tensor(:)-template_tensor(:)).^2);
MSEa=[mse052 mse083 mse328 mse329 mse354 mse383 mse386 mse396 mse438 mse439];
MSE=(mse052+mse083+mse328+mse329+mse354+mse383+mse386+mse396+mse438+mse439)/10;
RMSE=(sqrt(mse052)+sqrt(mse083)+sqrt(mse328)+sqrt(mse329)+sqrt(mse354)+sqrt(mse383)+sqrt(mse386)+sqrt(mse396)+sqrt(mse438)+sqrt(mse439))/10;
MSEa
MSE
RMSE