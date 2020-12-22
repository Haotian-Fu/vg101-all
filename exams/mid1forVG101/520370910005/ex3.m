load mandrill.mat
imwrite(X,map,'mandrill.png')
image= imread('mandrill.png');
[Y,image] = cmpermute(X,map);
colormap(image)