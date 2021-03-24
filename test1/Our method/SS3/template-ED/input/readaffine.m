function re_affine_dtidata=readaffine()
[filename pathname] = uigetfile('*.raw','Please select a RAW file');
fid = fopen([pathname filename],'rb');
affine_img=fread(fid,'*float');%读入DTI的数据排成一列，存储在img中

affine_img=reshape(affine_img,128,128,64);%将读入的DTI数据排列成6*128*128*64的矩阵形式，存储在img中
fclose(fid);
affine_mri=cell(128,128,64);%构造128*128*64的空矩阵cell,赋值给mri用于存储张量体素的9个分量，其排列顺序为
                     %Dxx,Dxy,Dxz,Dyx,Dyy,Dyz,Dzx,Dzy,Dzz
for x=1:128          
     for y=1:128     
        for z=1:64
            affine_mri{x,y,z}=affine_img(x,y,z);            
        end
    end
end

%  for x=1:128          
%      for y=1:128     
%         for z=1:64
%            re_mri=img(:,x,y,z);  
%             re_mri{:,x,y,z}=[re_mri(1) re_mri(4) re_mri(5) re_mri(4) re_mri(2) re_mri(6) re_mri(5) re_mri(6) re_mri(3)];
%         end
%     end
% end
        
            
%%
%dtidata存放DTI数据
%affine_dtidata=cell(128,128,64);%把mri中每个元素的9个分量按照DTI3*3对称矩阵的形式存储
%re_affine_dtidata=cell(128,128,64);
%for x=1:128
%    for y=1:128
%        for z=1:64
%            affine_dtidata{x,y,z}=[affine_mri{x,y,z}(1,1),affine_mri{x,y,z}(4,1),affine_mri{x,y,z}(5,1);
%                            affine_mri{x,y,z}(4,1),affine_mri{x,y,z}(2,1),affine_mri{x,y,z}(6,1);
%                            affine_mri{x,y,z}(5,1),affine_mri{x,y,z}(6,1),affine_mri{x,y,z}(3,1)];
%             re_affine_dtidata{x,y,z}=reshape(affine_dtidata{x,y,z},3,3);
%       end
%    end
%end



