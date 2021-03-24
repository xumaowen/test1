clear all;
clc
%º∆À„≈∑ Ωæ‡¿Î

re_dtitk0_dtidata=readdtitk();
re_dtitk1_dtidata=readdtitk();


dtitk_dist1=zeros(128,128,64);



for x=1:128
    for y=1:128
        for z=1:64
            dtitk_dist1(x,y,z)=norm(re_dtitk1_dtidata{x,y,z}-re_dtitk0_dtidata{x,y,z});
        end
    end
end



save dtitk_dist1 dtitk_dist1;






 
 