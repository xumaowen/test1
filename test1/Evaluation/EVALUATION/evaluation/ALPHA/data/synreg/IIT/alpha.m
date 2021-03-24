clear all;
clc;


[filename pathname]=uigetfile('*.nii');
dtitk_s1_v1=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s1_v2=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s1_v3=load_nii(filename,[],1);


[filename pathname]=uigetfile('*.nii');
dtitk_s2_v1=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s2_v2=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s2_v3=load_nii(filename,[],1);


[filename pathname]=uigetfile('*.nii');
dtitk_s3_v1=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s3_v2=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s3_v3=load_nii(filename,[],1);


[filename pathname]=uigetfile('*.nii');
dtitk_s4_v1=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s4_v2=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s4_v3=load_nii(filename,[],1);



[filename pathname]=uigetfile('*.nii');
dtitk_s5_v1=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s5_v2=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s5_v3=load_nii(filename,[],1);



[filename pathname]=uigetfile('*.nii');
dtitk_s6_v1=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s6_v2=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s6_v3=load_nii(filename,[],1);


[filename pathname]=uigetfile('*.nii');
dtitk_s7_v1=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s7_v2=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s7_v3=load_nii(filename,[],1);


[filename pathname]=uigetfile('*.nii');
dtitk_s8_v1=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s8_v2=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s8_v3=load_nii(filename,[],1);

[filename pathname]=uigetfile('*.nii');
dtitk_s9_v1=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s9_v2=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s9_v3=load_nii(filename,[],1);



[filename pathname]=uigetfile('*.nii');
dtitk_s10_v1=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s10_v2=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
dtitk_s10_v3=load_nii(filename,[],1);


[filename pathname]=uigetfile('*.nii');
template_v1=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
template_v2=load_nii(filename,[],1);
[filename pathname]=uigetfile('*.nii');
template_v3=load_nii(filename,[],1);

dtitk_s1_alpha1=zeros(128,128,64);
dtitk_s1_alpha2=zeros(128,128,64);
dtitk_s1_alpha3=zeros(128,128,64);
dtitk_s1_alpha=zeros(128,128,64);

dtitk_s2_alpha1=zeros(128,128,64);
dtitk_s2_alpha2=zeros(128,128,64);
dtitk_s2_alpha3=zeros(128,128,64);
dtitk_s2_alpha=zeros(128,128,64);


dtitk_s3_alpha1=zeros(128,128,64);
dtitk_s3_alpha2=zeros(128,128,64);
dtitk_s3_alpha3=zeros(128,128,64);
dtitk_s3_alpha=zeros(128,128,64);


dtitk_s4_alpha1=zeros(128,128,64);
dtitk_s4_alpha2=zeros(128,128,64);
dtitk_s4_alpha3=zeros(128,128,64);
dtitk_s4_alpha=zeros(128,128,64);

dtitk_s5_alpha1=zeros(128,128,64);
dtitk_s5_alpha2=zeros(128,128,64);
dtitk_s5_alpha3=zeros(128,128,64);
dtitk_s5_alpha=zeros(128,128,64);

dtitk_s6_alpha1=zeros(128,128,64);
dtitk_s6_alpha2=zeros(128,128,64);
dtitk_s6_alpha3=zeros(128,128,64);
dtitk_s6_alpha=zeros(128,128,64);

dtitk_s7_alpha1=zeros(128,128,64);
dtitk_s7_alpha2=zeros(128,128,64);
dtitk_s7_alpha3=zeros(128,128,64);
dtitk_s7_alpha=zeros(128,128,64);

dtitk_s8_alpha1=zeros(128,128,64);
dtitk_s8_alpha2=zeros(128,128,64);
dtitk_s8_alpha3=zeros(128,128,64);
dtitk_s8_alpha=zeros(128,128,64);

dtitk_s9_alpha1=zeros(128,128,64);
dtitk_s9_alpha2=zeros(128,128,64);
dtitk_s9_alpha3=zeros(128,128,64);
dtitk_s9_alpha=zeros(128,128,64);

dtitk_s10_alpha1=zeros(128,128,64);
dtitk_s10_alpha2=zeros(128,128,64);
dtitk_s10_alpha3=zeros(128,128,64);
dtitk_s10_alpha=zeros(128,128,64);

atlas_alpha1=zeros(128,128,64);
atlas_alpha2=zeros(128,128,64);
atlas_alpha3=zeros(128,128,64);
atlas_alpha=zeros(128,128,64);

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s1_alpha1(x,y,z)=acos((dtitk_s1_v1.img(x,y,z)*template_v1.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s1_v1.img(x,y,z)*dtitk_s1_v1.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v1.img(x,y,z)*template_v1.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s1_alpha2(x,y,z)=acos((dtitk_s1_v2.img(x,y,z)*template_v2.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s1_v2.img(x,y,z)*dtitk_s1_v2.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v2.img(x,y,z)*template_v2.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s1_alpha3(x,y,z)=acos((dtitk_s1_v3.img(x,y,z)*template_v3.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s1_v3.img(x,y,z)*dtitk_s1_v3.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v3.img(x,y,z)*template_v3.img(x,y,z))))))));
        end
    end
end

dtitk_s1_alpha=(dtitk_s1_alpha1+dtitk_s1_alpha2+dtitk_s1_alpha3)/3;

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s2_alpha1(x,y,z)=acos((dtitk_s2_v1.img(x,y,z)*template_v1.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s2_v1.img(x,y,z)*dtitk_s2_v1.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v1.img(x,y,z)*template_v1.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s2_alpha2(x,y,z)=acos((dtitk_s2_v2.img(x,y,z)*template_v2.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s2_v2.img(x,y,z)*dtitk_s2_v2.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v2.img(x,y,z)*template_v2.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s2_alpha3(x,y,z)=acos((dtitk_s2_v3.img(x,y,z)*template_v3.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s2_v3.img(x,y,z)*dtitk_s2_v3.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v3.img(x,y,z)*template_v3.img(x,y,z))))))));
        end
    end
end

dtitk_s2_alpha=(dtitk_s2_alpha1+dtitk_s2_alpha2+dtitk_s2_alpha3)/3;

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s3_alpha1(x,y,z)=acos((dtitk_s3_v1.img(x,y,z)*template_v1.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s3_v1.img(x,y,z)*dtitk_s3_v1.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v1.img(x,y,z)*template_v1.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s3_alpha2(x,y,z)=acos((dtitk_s3_v2.img(x,y,z)*template_v2.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s3_v2.img(x,y,z)*dtitk_s3_v2.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v2.img(x,y,z)*template_v2.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s3_alpha3(x,y,z)=acos((dtitk_s3_v3.img(x,y,z)*template_v3.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s3_v3.img(x,y,z)*dtitk_s3_v3.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v3.img(x,y,z)*template_v3.img(x,y,z))))))));
        end
    end
end

dtitk_s3_alpha=(dtitk_s3_alpha1+dtitk_s3_alpha2+dtitk_s3_alpha3)/3;

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s4_alpha1(x,y,z)=acos((dtitk_s4_v1.img(x,y,z)*template_v1.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s4_v1.img(x,y,z)*dtitk_s4_v1.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v1.img(x,y,z)*template_v1.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s4_alpha2(x,y,z)=acos((dtitk_s4_v2.img(x,y,z)*template_v2.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s4_v2.img(x,y,z)*dtitk_s4_v2.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v2.img(x,y,z)*template_v2.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s4_alpha3(x,y,z)=acos((dtitk_s4_v3.img(x,y,z)*template_v3.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s4_v3.img(x,y,z)*dtitk_s4_v3.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v3.img(x,y,z)*template_v3.img(x,y,z))))))));
        end
    end
end

dtitk_s4_alpha=(dtitk_s4_alpha1+dtitk_s4_alpha2+dtitk_s4_alpha3)/3;


for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s5_alpha1(x,y,z)=acos((dtitk_s5_v1.img(x,y,z)*template_v1.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s5_v1.img(x,y,z)*dtitk_s5_v1.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v1.img(x,y,z)*template_v1.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s5_alpha2(x,y,z)=acos((dtitk_s5_v2.img(x,y,z)*template_v2.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s5_v2.img(x,y,z)*dtitk_s5_v2.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v2.img(x,y,z)*template_v2.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s5_alpha3(x,y,z)=acos((dtitk_s5_v3.img(x,y,z)*template_v3.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s5_v3.img(x,y,z)*dtitk_s5_v3.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v3.img(x,y,z)*template_v3.img(x,y,z))))))));
        end
    end
end

dtitk_s5_alpha=(dtitk_s5_alpha1+dtitk_s5_alpha2+dtitk_s5_alpha3)/3;


for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s6_alpha1(x,y,z)=acos((dtitk_s6_v1.img(x,y,z)*template_v1.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s6_v1.img(x,y,z)*dtitk_s6_v1.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v1.img(x,y,z)*template_v1.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s6_alpha2(x,y,z)=acos((dtitk_s6_v2.img(x,y,z)*template_v2.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s6_v2.img(x,y,z)*dtitk_s6_v2.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v2.img(x,y,z)*template_v2.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s6_alpha3(x,y,z)=acos((dtitk_s6_v3.img(x,y,z)*template_v3.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s6_v3.img(x,y,z)*dtitk_s6_v3.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v3.img(x,y,z)*template_v3.img(x,y,z))))))));
        end
    end
end

dtitk_s6_alpha=(dtitk_s6_alpha1+dtitk_s6_alpha2+dtitk_s6_alpha3)/3;


for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s7_alpha1(x,y,z)=acos((dtitk_s7_v1.img(x,y,z)*template_v1.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s7_v1.img(x,y,z)*dtitk_s7_v1.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v1.img(x,y,z)*template_v1.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s7_alpha2(x,y,z)=acos((dtitk_s7_v2.img(x,y,z)*template_v2.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s7_v2.img(x,y,z)*dtitk_s7_v2.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v2.img(x,y,z)*template_v2.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s7_alpha3(x,y,z)=acos((dtitk_s7_v3.img(x,y,z)*template_v3.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s7_v3.img(x,y,z)*dtitk_s7_v3.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v3.img(x,y,z)*template_v3.img(x,y,z))))))));
        end
    end
end

dtitk_s7_alpha=(dtitk_s7_alpha1+dtitk_s7_alpha2+dtitk_s7_alpha3)/3;

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s8_alpha1(x,y,z)=acos((dtitk_s8_v1.img(x,y,z)*template_v1.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s8_v1.img(x,y,z)*dtitk_s8_v1.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v1.img(x,y,z)*template_v1.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s8_alpha2(x,y,z)=acos((dtitk_s8_v2.img(x,y,z)*template_v2.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s8_v2.img(x,y,z)*dtitk_s8_v2.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v2.img(x,y,z)*template_v2.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s8_alpha3(x,y,z)=acos((dtitk_s8_v3.img(x,y,z)*template_v3.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s8_v3.img(x,y,z)*dtitk_s8_v3.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v3.img(x,y,z)*template_v3.img(x,y,z))))))));
        end
    end
end

dtitk_s8_alpha=(dtitk_s8_alpha1+dtitk_s8_alpha2+dtitk_s8_alpha3)/3;

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s9_alpha1(x,y,z)=acos((dtitk_s9_v1.img(x,y,z)*template_v1.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s9_v1.img(x,y,z)*dtitk_s9_v1.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v1.img(x,y,z)*template_v1.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s9_alpha2(x,y,z)=acos((dtitk_s9_v2.img(x,y,z)*template_v2.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s9_v2.img(x,y,z)*dtitk_s9_v2.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v2.img(x,y,z)*template_v2.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s9_alpha3(x,y,z)=acos((dtitk_s9_v3.img(x,y,z)*template_v3.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s9_v3.img(x,y,z)*dtitk_s9_v3.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v3.img(x,y,z)*template_v3.img(x,y,z))))))));
        end
    end
end

dtitk_s9_alpha=(dtitk_s9_alpha1+dtitk_s9_alpha2+dtitk_s9_alpha3)/3;

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s10_alpha1(x,y,z)=acos((dtitk_s10_v1.img(x,y,z)*template_v1.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s10_v1.img(x,y,z)*dtitk_s10_v1.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v1.img(x,y,z)*template_v1.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s10_alpha2(x,y,z)=acos((dtitk_s10_v2.img(x,y,z)*template_v2.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s10_v2.img(x,y,z)*dtitk_s10_v2.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v2.img(x,y,z)*template_v2.img(x,y,z))))))));
        end
    end
end

for x=1:256
    for y=1:256
        for z=1:256
  dtitk_s10_alpha3(x,y,z)=acos((dtitk_s10_v3.img(x,y,z)*template_v3.img(x,y,z))/...
 ( sqrt(sum(sum(sum((dtitk_s10_v3.img(x,y,z)*dtitk_s10_v3.img(x,y,z))))))*...
 sqrt(sum(sum(sum((template_v3.img(x,y,z)*template_v3.img(x,y,z))))))));
        end
    end
end

dtitk_s10_alpha=(dtitk_s10_alpha1+dtitk_s10_alpha2+dtitk_s10_alpha3)/3;

IIT_alpha1=(dtitk_s1_alpha1+dtitk_s2_alpha1+dtitk_s3_alpha1+dtitk_s4_alpha1+dtitk_s5_alpha1+...
    dtitk_s6_alpha1+dtitk_s7_alpha1+dtitk_s8_alpha1+dtitk_s9_alpha1+dtitk_s10_alpha1)/10;
IIT_alpha2=(dtitk_s1_alpha2+dtitk_s2_alpha2+dtitk_s3_alpha2+dtitk_s4_alpha2+dtitk_s5_alpha2+...
    dtitk_s6_alpha2+dtitk_s7_alpha2+dtitk_s8_alpha2+dtitk_s9_alpha2+dtitk_s10_alpha2)/10;
IIT_alpha3=(dtitk_s1_alpha3+dtitk_s2_alpha3+dtitk_s3_alpha3+dtitk_s4_alpha3+dtitk_s5_alpha3+...
    dtitk_s6_alpha3+dtitk_s7_alpha3+dtitk_s8_alpha3+dtitk_s9_alpha3+dtitk_s10_alpha3)/10;
IIT_alpha=(dtitk_s1_alpha+dtitk_s2_alpha+dtitk_s3_alpha+dtitk_s4_alpha+dtitk_s5_alpha+...
    dtitk_s6_alpha+dtitk_s7_alpha+dtitk_s8_alpha+dtitk_s9_alpha+dtitk_s10_alpha)/10;


 save IIT_alpha1 IIT_alpha1;
save IIT_alpha2 IIT_alpha2;
save IIT_alpha3 IIT_alpha3;
save IIT_alpha IIT_alpha;
