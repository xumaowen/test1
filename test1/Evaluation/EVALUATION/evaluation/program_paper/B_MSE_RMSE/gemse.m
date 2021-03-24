clear all;
clc;
sub052=importdata('Genu\affine052_genue corpus callosum Fiber Bundle_fa__Clean.txt'); % 读取纤维束数据
sub052_tensor=sub052(7977:25654,:);
sub083=importdata('Genu\affine083_genue corpus callosum Fiber Bundle_fa__Clean.txt');
sub083_tensor=sub083(7977:25654,:);
sub328=importdata('Genu\affine328_genue corpus callosum Fiber Bundle_fa__Clean.txt');
sub328_tensor=sub328(7977:25654,:);
sub329=importdata('Genu\affine329_genue corpus callosum Fiber Bundle_fa__Clean.txt');
sub329_tensor=sub329(7977:25654,:);
sub354=importdata('Genu\affine354_genue corpus callosum Fiber Bundle_fa__Clean.txt');
sub354_tensor=sub354(7977:25654,:);
sub383=importdata('Genu\affine383_genue corpus callosum Fiber Bundle_fa__Clean.txt');
sub383_tensor=sub383(7977:25654,:);
sub386=importdata('Genu\affine386_genue corpus callosum Fiber Bundle_fa__Clean.txt');
sub386_tensor=sub386(7977:25654,:);
sub396=importdata('Genu\affine396_genue corpus callosum Fiber Bundle_fa__Clean.txt');
sub396_tensor=sub396(7977:25654,:);
sub438=importdata('Genu\affine438_genue corpus callosum Fiber Bundle_fa__Clean.txt');
sub438_tensor=sub438(7977:25654,:);
sub439=importdata('Genu\affine439_genue corpus callosum Fiber Bundle_fa__Clean.txt');
sub439_tensor=sub439(7977:25654,:);
template=importdata('Genu\template_genue corpus callosum Fiber Bundle_fa__Clean.txt');
template_tensor=template(7977:25654,:);
mse052=mean((sub052_tensor(:)-template_tensor(:)).^2); % 计算subject052与template之间的MSE
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
MSE=(mse052+mse083+mse328+mse329+mse354+mse383+mse386+mse396+mse438+mse439)/10; % 计算所有subject与template之间的平均MSE
RMSE=(sqrt(mse052)+sqrt(mse083)+sqrt(mse328)+sqrt(mse329)+sqrt(mse354)+sqrt(mse383)+sqrt(mse386)+sqrt(mse396)+sqrt(mse438)+sqrt(mse439))/10; % 计算所有subject与template之间的平均RMSE
MSEa
MSE
RMSE