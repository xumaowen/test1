a=load_nii('atlas-fa.nii.gz');
%a=load_nii('dtitk-fa.nii.gz');
%a=load_nii('w-fa.nii.gz');
b=a.img;
c=zeros(128,128);


 
  for y=1:128;
        for x=1:128;
         
            c(x,y)=b(x,y,32);
            
        end
  end

c=imrotate(c,90);%Ðý×ª
imshow(c);


E=entropy(c);