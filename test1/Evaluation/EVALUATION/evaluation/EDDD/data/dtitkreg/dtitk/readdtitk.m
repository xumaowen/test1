function re_dtitk_dtidata=readdtitk()
[filename pathname] = uigetfile('*.raw','Please select a RAW file');
fid = fopen([pathname filename],'rb');
dtitk_img=fread(fid,'*float');%读入DTI的数据排成一列，存储在img中
dtitk_img=reshape(dtitk_img,6,128,128,64);%将读入的DTI数据排列成6*128*128*64的矩阵形式，存储在img中
fclose(fid);
dtitk_mri=cell(128,128,64);%构造128*128*64的空矩阵cell,赋值给mri用于存储张量体素的9个分量，其排列顺序为
                     %Dxx,Dxy,Dxz,Dyx,Dyy,Dyz,Dzx,Dzy,Dzz
for x=1:128          
     for y=1:128     
        for z=1:64
            dtitk_mri{x,y,z}=dtitk_img(:,x,y,z);            
        end
    end
end


%dtidata存放DTI数据
dtitk_dtidata=cell(128,128,64);%把mri中每个元素的9个分量按照DTI3*3对称矩阵的形式存储
re_dtitk_dtidata=cell(128,128,64);
for x=1:128
    for y=1:128
        for z=1:64
            dtitk_dtidata{x,y,z}=[dtitk_mri{x,y,z}(1,1),dtitk_mri{x,y,z}(4,1),dtitk_mri{x,y,z}(5,1);
                            dtitk_mri{x,y,z}(4,1),dtitk_mri{x,y,z}(2,1),dtitk_mri{x,y,z}(6,1);
                            dtitk_mri{x,y,z}(5,1),dtitk_mri{x,y,z}(6,1),dtitk_mri{x,y,z}(3,1)];
             re_dtitk_dtidata{x,y,z}=reshape(dtitk_dtidata{x,y,z},3,3);
        end
    end
end
