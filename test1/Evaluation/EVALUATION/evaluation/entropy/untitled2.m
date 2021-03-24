clear;
clc;

%a=load_nii('atlas-fa.nii.gz');
%a=load_nii('dtitk-fa.nii.gz');
a=load_nii('NTU-fa.nii.gz');
b=a.img;
c=zeros(256,256);



  for y=1:256;
        for x=1:256;
         
            c(x,y)=b(x,y,128);
            
        end
  end

c=imrotate(c,90);%Ðý×ª
imshow(c);
[Gmag, Gdir] = imgradient(c,'CentralDifference');

figure
imshow(Gmag);

mean=mean2(Gmag(Gmag~=0));