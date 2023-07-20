# stereo_pair
Implementation of Stereo Pair using C++/OpenGL

2D 이미지 2개로 물체의 원근감을 느낄 수 있도록 하기 위하여 ViewPort 2개로 두 개의 이미지를 만들었다.


![image](https://github.com/ndb796/React-Multi-Page-Web-Template-1/assets/129146537/2453d66a-2513-49be-a277-640f5179d458)
왼쪽 이미지는 오른쪽 눈으로 보는 이미지를,
오른쪽 이미지는 왼쪽 눈으로 보는 이미지를 나타낸 것이다.  


쉽게 원근감을 체험하기 위해서는 사팔뜨기로 2개의 이미지를 4개의 이미지로 보이게 만든다.  
이제 4개의 이미지 중, 가운데 있는 이미지 2개를 합쳐 하나의 이미지로 만든다.  
이제, 가운데 합쳐진 이미지는 원근이 적용된 이미지로 보일 것이다.
