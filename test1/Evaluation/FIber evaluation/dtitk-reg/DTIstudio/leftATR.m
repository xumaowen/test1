clear all;
clc;
[filename pathname]=uigetfile('*.dat');
fid_sub_052 = fopen([pathname filename]);%%fopen  subject_052 FiberL-ATR.dat
sub_052 = fread(fid_sub_052);

[filename pathname]=uigetfile('*.dat');
fid_tem_052 = fopen([pathname filename]);%%fopen  template_FiberL-ATR..dat
template_052 = fread(fid_tem_052);

[filename pathname]=uigetfile('*.dat');
fid_sub_083 = fopen([pathname filename]);%%fopen  subject_083 FiberL-ATR.
sub_083 = fread(fid_sub_083);
[filename pathname]=uigetfile('*.dat');
fid_tem_083 =  fopen([pathname filename]);%%fopen  template_FiberL-ATR.dat,ÏÂÍ¬
template_083 = fread(fid_tem_083);

[filename pathname]=uigetfile('*.dat');
fid_sub_328 = fopen([pathname filename]);
sub_328 = fread(fid_sub_328);
[filename pathname]=uigetfile('*.dat');
fid_tem_328 =fopen([pathname filename]);
template_328 = fread(fid_tem_328);

[filename pathname]=uigetfile('*.dat');
fid_sub_329 = fopen([pathname filename]);
sub_329 = fread(fid_sub_329);
[filename pathname]=uigetfile('*.dat');
fid_tem_329 =fopen([pathname filename]);
template_329 = fread(fid_tem_329);

[filename pathname]=uigetfile('*.dat');
fid_sub_354 = fopen([pathname filename]);
sub_354 = fread(fid_sub_354);
[filename pathname]=uigetfile('*.dat');
fid_tem_354 = fopen([pathname filename]);
template_354 = fread(fid_tem_354 );

[filename pathname]=uigetfile('*.dat');
fid_sub_383 =  fopen([pathname filename]);
sub_383 = fread(fid_sub_383);
[filename pathname]=uigetfile('*.dat');
fid_tem_383 = fopen([pathname filename]);
template_383 = fread(fid_tem_383);

[filename pathname]=uigetfile('*.dat');
fid_sub_386 =  fopen([pathname filename]);
sub_386 = fread(fid_sub_386 );
[filename pathname]=uigetfile('*.dat');
fid_tem_386 =fopen([pathname filename]);
template_386 = fread(fid_tem_386);

[filename pathname]=uigetfile('*.dat');
fid_sub_396 =  fopen([pathname filename]);
sub_396 = fread(fid_sub_396);
[filename pathname]=uigetfile('*.dat');
fid_tem_396 =  fopen([pathname filename]);
template_396 = fread(fid_tem_396);

[filename pathname]=uigetfile('*.dat');
fid_sub_438 =fopen([pathname filename]);
sub_438 = fread(fid_sub_438);
[filename pathname]=uigetfile('*.dat');
fid_tem_438 =fopen([pathname filename]);
template_438 = fread(fid_tem_438);

[filename pathname]=uigetfile('*.dat');
fid_sub_439=fopen([pathname filename]);
sub_439 = fread(fid_sub_439);
[filename pathname]=uigetfile('*.dat');
fid_tem_439 =fopen([pathname filename]);
template_439 = fread(fid_tem_439);

% fid_tem = fopen('E:\yu\yu1\program\new\evaluation\fiber dist\template\FiberATR.dat','r');
% template = fread(fid_tem);


% [filename pathname] = uigetfile('.hdr');
% sub=load_nii(filename);
% [filename pathname] = uigetfile('.hdr');
% template=load_nii(filename);
%  fiber_sub=sub.img(:);
% fiber_tem=template.img(:);

size052_max=max(size(sub_052),size(template_052));
sub_052(size052_max,:)=0;
template_052(size052_max,:)=0;

size083_max=max(size(sub_083),size(template_083));
sub_083(size083_max,:)=0;
template_083(size083_max,:)=0;

size328_max=max(size(sub_328),size(template_328));
sub_328(size328_max,:)=0;
template_328(size328_max,:)=0;

size329_max=max(size(sub_329),size(template_329));
sub_329(size329_max,:)=0;
template_329(size329_max,:)=0;

size354_max=max(size(sub_354),size(template_354));
sub_354(size354_max,:)=0;
template_354(size354_max,:)=0;

size383_max=max(size(sub_383),size(template_383));
sub_383(size383_max,:)=0;
template_383(size383_max,:)=0;


size386_max=max(size(sub_386),size(template_386));
sub_386(size386_max,:)=0;
template_386(size386_max,:)=0;


size396_max=max(size(sub_396),size(template_396));
sub_396(size396_max,:)=0;
template_396(size396_max,:)=0;

size438_max=max(size(sub_438),size(template_438));
sub_438(size438_max,:)=0;
template_438(size438_max,:)=0;

size439_max=max(size(sub_439),size(template_439));
sub_439(size439_max,:)=0;
template_439(size439_max,:)=0;

F_sum_052=norm(sub_052)+norm(template_052);
F_sum_083=norm(sub_083)+norm(template_083);
F_sum_328=norm(sub_328)+norm(template_328);
F_sum_329=norm(sub_329)+norm(template_329);
F_sum_354=norm(sub_354)+norm(template_354);
F_sum_383=norm(sub_383)+norm(template_383);
F_sum_386=norm(sub_386)+norm(template_386);
F_sum_396=norm(sub_396)+norm(template_396);
F_sum_438=norm(sub_438)+norm(template_438);
F_sum_439=norm(sub_439)+norm(template_439);



affine_F_data_052= sub_052';
affine_F_data_083= sub_083';
affine_F_data_328= sub_328';
affine_F_data_329= sub_329';
affine_F_data_354= sub_354';
affine_F_data_383= sub_383';
affine_F_data_386= sub_386';
affine_F_data_396= sub_396';
affine_F_data_438= sub_438';
affine_F_data_439= sub_439';

template_G_data_052=template_052';
template_G_data_083=template_083';
template_G_data_328=template_328';
template_G_data_329=template_329';
template_G_data_354=template_354';
template_G_data_383=template_383';
template_G_data_386=template_386';
template_G_data_396=template_396';
template_G_data_438=template_438';
template_G_data_439=template_439';


d_052=HausdorffDist(affine_F_data_052,template_G_data_052);
d_083=HausdorffDist(affine_F_data_083,template_G_data_083);
d_328=HausdorffDist(affine_F_data_328,template_G_data_328);
d_329=HausdorffDist(affine_F_data_329,template_G_data_329);
d_354=HausdorffDist(affine_F_data_354,template_G_data_354);
d_383=HausdorffDist(affine_F_data_383,template_G_data_383);
d_386=HausdorffDist(affine_F_data_386,template_G_data_386);
d_396=HausdorffDist(affine_F_data_396,template_G_data_396);
d_438=HausdorffDist(affine_F_data_438,template_G_data_438);
d_439=HausdorffDist(affine_F_data_439,template_G_data_439);

  d_affine_052=d_052/F_sum_052
  d_affine_083=d_083/F_sum_083
  d_affine_328=d_328/F_sum_328
  d_affine_329=d_329/F_sum_329
  d_affine_354=d_354/F_sum_354
  d_affine_383=d_383/F_sum_383
  d_affine_386=d_386/F_sum_386
  d_affine_396=d_396/F_sum_396
  d_affine_438=d_438/F_sum_438
  d_affine_439=d_439/F_sum_439
 
 d_affine_ave=(d_affine_052+d_affine_083+d_affine_328+d_affine_329+...
     +d_affine_354+d_affine_383+d_affine_386+d_affine_396+d_affine_438+d_affine_439)/10
 
 
 
 
 