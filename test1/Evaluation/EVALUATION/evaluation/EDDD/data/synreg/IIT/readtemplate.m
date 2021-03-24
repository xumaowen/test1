function tem_re_dtidata=readtemplate()
%读取模板数据
[filename pathname] = uigetfile('*.raw','Please select a RAW file');
fid = fopen([pathname filename],'rb');
tem=fread(fid,'*float');%读入DTI的数据排成一列，存储在img中
tem=reshape(tem,6,256,256,256);%将读入的DTI数据排列成9*128*128*64的矩阵形式，存储在img中
fclose(fid);
tem_mri=cell(256,256,256);%构造128*128*64的空矩阵cell,赋值给mri用于存储张量体素的9个分量，其排列顺序为
                     %Dxx,Dxy,Dxz,Dyx,Dyy,Dyz,Dzx,Dzy,Dzz
for x=1:256          
     for y=1:256   
        for z=1:256
            tem_mri{x,y,z}=tem(:,x,y,z);
        end
    end
end
%dtidata存放DTI数据
tem_dtidata=cell(256,256,256);%把mri中每个元素的9个分量按照DTI3*3对称矩阵的形式存储
tem_re_dtidata=cell(256,256,256);
for x=1:256
    for y=1:256
        for z=1:256
            tem_dtidata{x,y,z}=[tem_mri{x,y,z}(1,1),tem_mri{x,y,z}(4,1),tem_mri{x,y,z}(5,1);
                            tem_mri{x,y,z}(4,1),tem_mri{x,y,z}(2,1),tem_mri{x,y,z}(6,1);
                            tem_mri{x,y,z}(5,1),tem_mri{x,y,z}(6,1),tem_mri{x,y,z}(3,1)];
             tem_re_dtidata{x,y,z}=reshape(tem_dtidata{x,y,z},3,3);
        end
    end
end