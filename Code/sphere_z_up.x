xof 0303txt 0032

// DirectX 9.0 file
// Creator: Ultimate Unwrap3D Pro v3.50.21
// Website: http://www.unwrap3d.com
// Time: Mon Nov 21 20:29:55 2016

// Start of Templates

template VertexDuplicationIndices {
 <b8d65549-d7c9-4995-89cf-53a9a8b031e3>
 DWORD nIndices;
 DWORD nOriginalVertices;
 array DWORD indices[nIndices];
}

template FVFData {
 <b6e70a0e-8ef9-4e83-94ad-ecc8b0c04897>
 DWORD dwFVF;
 DWORD nDWords;
 array DWORD data[nDWords];
}

template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template FrameTransformMatrix {
 <F6F23F41-7686-11cf-8F52-0040333594A3>
 Matrix4x4 frameMatrix;
}

template Frame {
 <3D82AB46-62DA-11cf-AB39-0020AF71E433>
 [...]
}

template FloatKeys {
 <10DD46A9-775B-11cf-8F52-0040333594A3>
 DWORD nValues;
 array FLOAT values[nValues];
}

template TimedFloatKeys {
 <F406B180-7B3B-11cf-8F52-0040333594A3>
 DWORD time;
 FloatKeys tfkeys;
}

template AnimationKey {
 <10DD46A8-775B-11cf-8F52-0040333594A3>
 DWORD keyType;
 DWORD nKeys;
 array TimedFloatKeys keys[nKeys];
}

template AnimationOptions {
 <E2BF56C0-840F-11cf-8F52-0040333594A3>
 DWORD openclosed;
 DWORD positionquality;
}

template Animation {
 <3D82AB4F-62DA-11cf-AB39-0020AF71E433>
 [...]
}

template AnimationSet {
 <3D82AB50-62DA-11cf-AB39-0020AF71E433>
 [Animation]
}

template XSkinMeshHeader {
 <3CF169CE-FF7C-44ab-93C0-F78F62D172E2>
 WORD nMaxSkinWeightsPerVertex;
 WORD nMaxSkinWeightsPerFace;
 WORD nBones;
}

template SkinWeights {
 <6F0D123B-BAD2-4167-A0D0-80224F25FABB>
 STRING transformNodeName;
 DWORD nWeights;
 array DWORD vertexIndices[nWeights];
 array FLOAT weights[nWeights];
 Matrix4x4 matrixOffset;
}

template AnimTicksPerSecond {
 <9E415A43-7BA6-4a73-8743-B73D47E88476>
 DWORD AnimTicksPerSecond;
}

AnimTicksPerSecond {
 4800;
}

// Start of Frames

   Frame Body {
      FrameTransformMatrix {
       1.000000, 0.000000, 0.000000, 0.000000,
       0.000000, 1.000000, 0.000000, 0.000000,
       0.000000, 0.000000, 1.000000, 0.000000,
       0.000000, 0.000000, 0.000000, 1.000000;;
      }

   }

   Frame Body0 {
      FrameTransformMatrix {
       1.000000, 0.000000, 0.000000, 0.000000,
       0.000000, 1.000000, 0.000000, 0.000000,
       0.000000, 0.000000, 1.000000, 0.000000,
       0.000000, 0.000000, 0.000000, 1.000000;;
      }

      Mesh skinnedMesh {
       92;
       764.275330; 376.367249; 1029.394043;,
       1194.586914; 293.739655; 838.100037;,
       959.853577; 11.785275; 1029.340332;,
       533.110107; 690.268066; 890.830811;,
       973.018433; 667.642334; 775.663025;,
       1335.788086; 536.139404; 534.002197;,
       297.486328; 911.218323; 632.309448;,
       696.284119; 970.388489; 539.411316;,
       1068.650513; 898.887390; 373.876678;,
       1364.443115; 706.343262; 157.996277;,
       1257.717041; -179.635925; 815.316650;,
       1474.093994; 103.037399; 558.273743;,
       1453.547241; -346.867615; 491.503479;,
       1562.092163; 342.884186; 159.799316;,
       1616.721191; -66.747223; 140.083923;,
       1520.973999; -467.390533; 101.504967;,
       866.421936; -389.570435; 992.529846;,
       1140.852051; -590.843933; 715.092712;,
       723.648376; -738.467102; 822.066406;,
       1288.556152; -750.057312; 294.513672;,
       949.952393; -931.722229; 447.863525;,
       550.758606; -987.922729; 540.904602;,
       561.458191; -45.941574; 1124.836914;,
       433.821594; -455.081207; 1029.401367;,
       154.786957; -97.481987; 1068.864380;,
       253.693634; -798.027893; 757.383728;,
       -10.204071; -500.671661; 871.874573;,
       -205.398315; -135.895584; 868.959778;,
       330.094727; 322.706024; 1066.835938;,
       -112.350708; 265.266052; 908.738708;,
       63.155365; 630.707214; 826.148071;,
       -64.118652; 874.017212; 434.752441;,
       327.176392; 1083.951538; 257.539398;,
       -349.760010; 719.122009; 178.652222;,
       -27.850830; 996.145996; 14.557814;,
       380.138641; 1110.721313; -151.910660;,
       -520.973877; 467.390808; -101.505043;,
       -288.556030; 750.057495; -294.513672;,
       50.047577; 931.722351; -447.863464;,
       449.241302; 987.922729; -540.904541;,
       1129.854370; 929.822876; -99.289284;,
       1434.818115; 586.193970; -231.596359;,
       810.450256; 1028.093628; -343.204681;,
       1147.692993; 770.420105; -508.027496;,
       1379.311646; 387.108612; -590.002625;,
       746.306335; 798.027954; -757.383667;,
       1010.204041; 500.671722; -871.874573;,
       1205.398315; 135.895660; -868.959778;,
       1552.577271; -296.812988; -274.095093;,
       1349.760132; -719.121826; -178.652252;,
       1442.441772; -86.266991; -612.785950;,
       1320.154419; -522.767883; -570.268066;,
       1064.118652; -874.017151; -434.752472;,
       1112.350586; -265.266022; -908.738770;,
       936.844604; -630.707275; -826.148132;,
       702.513611; -911.218384; -632.309448;,
       619.861206; -1110.721313; 151.910721;,
       189.549683; -1028.093628; 343.204681;,
       672.823547; -1083.951660; -257.539337;,
       251.197556; -1096.276123; -86.149521;,
       -129.854370; -929.822937; 99.289314;,
       303.715912; -970.388550; -539.411255;,
       -68.650513; -898.887512; -373.876587;,
       -364.443115; -706.343384; -157.996307;,
       -379.311646; -387.108582; 590.002625;,
       -442.441895; 86.267128; 612.786011;,
       -434.818115; -586.194031; 231.596344;,
       -581.915649; -157.535660; 275.292755;,
       -552.577271; 296.813263; 274.095123;,
       -562.092163; -342.884216; -159.799316;,
       -616.721191; 66.747383; -140.083954;,
       748.802429; 1096.276123; 86.149567;,
       1581.915527; 157.535736; -275.292694;,
       1027.850830; -996.145874; -14.557785;,
       -147.692993; -770.420105; 508.027466;,
       -320.154541; 522.767944; 570.268127;,
       438.541779; 45.941597; -1124.836914;,
       133.578033; 389.570435; -992.529785;,
       40.146454; -11.785275; -1029.340332;,
       845.213013; 97.482040; -1068.864258;,
       566.178406; 455.081268; -1029.401367;,
       276.351563; 738.467163; -822.066406;,
       235.724640; -376.367279; -1029.394043;,
       466.889832; -690.268127; -890.830811;,
       669.905273; -322.706055; -1066.835938;,
       -194.586914; -293.739685; -838.100037;,
       -335.788086; -536.139465; -534.002197;,
       26.981598; -667.642395; -775.663025;,
       -257.716919; 179.636047; -815.316711;,
       -453.547119; 346.867798; -491.503540;,
       -474.093872; -103.037354; -558.273804;,
       -140.851929; 590.844055; -715.092590;;
       180;
       3;0, 1, 2;,
       3;3, 4, 0;,
       3;4, 1, 0;,
       3;4, 5, 1;,
       3;6, 7, 3;,
       3;7, 4, 3;,
       3;7, 8, 4;,
       3;8, 5, 4;,
       3;8, 9, 5;,
       3;1, 10, 2;,
       3;5, 11, 1;,
       3;11, 10, 1;,
       3;11, 12, 10;,
       3;9, 13, 5;,
       3;13, 11, 5;,
       3;13, 14, 11;,
       3;14, 12, 11;,
       3;14, 15, 12;,
       3;10, 16, 2;,
       3;12, 17, 10;,
       3;17, 16, 10;,
       3;17, 18, 16;,
       3;15, 19, 12;,
       3;19, 17, 12;,
       3;19, 20, 17;,
       3;20, 18, 17;,
       3;20, 21, 18;,
       3;16, 22, 2;,
       3;18, 23, 16;,
       3;23, 22, 16;,
       3;23, 24, 22;,
       3;21, 25, 18;,
       3;25, 23, 18;,
       3;25, 26, 23;,
       3;26, 24, 23;,
       3;26, 27, 24;,
       3;22, 0, 2;,
       3;24, 28, 22;,
       3;28, 0, 22;,
       3;28, 3, 0;,
       3;27, 29, 24;,
       3;29, 28, 24;,
       3;29, 30, 28;,
       3;30, 3, 28;,
       3;30, 6, 3;,
       3;31, 32, 6;,
       3;33, 34, 31;,
       3;34, 32, 31;,
       3;34, 35, 32;,
       3;36, 37, 33;,
       3;37, 34, 33;,
       3;37, 38, 34;,
       3;38, 35, 34;,
       3;38, 39, 35;,
       3;40, 41, 9;,
       3;42, 43, 40;,
       3;43, 41, 40;,
       3;43, 44, 41;,
       3;39, 45, 42;,
       3;45, 43, 42;,
       3;45, 46, 43;,
       3;46, 44, 43;,
       3;46, 47, 44;,
       3;48, 49, 15;,
       3;50, 51, 48;,
       3;51, 49, 48;,
       3;51, 52, 49;,
       3;47, 53, 50;,
       3;53, 51, 50;,
       3;53, 54, 51;,
       3;54, 52, 51;,
       3;54, 55, 52;,
       3;56, 57, 21;,
       3;58, 59, 56;,
       3;59, 57, 56;,
       3;59, 60, 57;,
       3;55, 61, 58;,
       3;61, 59, 58;,
       3;61, 62, 59;,
       3;62, 60, 59;,
       3;62, 63, 60;,
       3;64, 65, 27;,
       3;66, 67, 64;,
       3;67, 65, 64;,
       3;67, 68, 65;,
       3;63, 69, 66;,
       3;69, 67, 66;,
       3;69, 70, 67;,
       3;70, 68, 67;,
       3;70, 36, 68;,
       3;42, 35, 39;,
       3;40, 71, 42;,
       3;71, 35, 42;,
       3;71, 32, 35;,
       3;9, 8, 40;,
       3;8, 71, 40;,
       3;8, 7, 71;,
       3;7, 32, 71;,
       3;7, 6, 32;,
       3;50, 44, 47;,
       3;48, 72, 50;,
       3;72, 44, 50;,
       3;72, 41, 44;,
       3;15, 14, 48;,
       3;14, 72, 48;,
       3;14, 13, 72;,
       3;13, 41, 72;,
       3;13, 9, 41;,
       3;58, 52, 55;,
       3;56, 73, 58;,
       3;73, 52, 58;,
       3;73, 49, 52;,
       3;21, 20, 56;,
       3;20, 73, 56;,
       3;20, 19, 73;,
       3;19, 49, 73;,
       3;19, 15, 49;,
       3;66, 60, 63;,
       3;64, 74, 66;,
       3;74, 60, 66;,
       3;74, 57, 60;,
       3;27, 26, 64;,
       3;26, 74, 64;,
       3;26, 25, 74;,
       3;25, 57, 74;,
       3;25, 21, 57;,
       3;33, 68, 36;,
       3;31, 75, 33;,
       3;75, 68, 33;,
       3;75, 65, 68;,
       3;6, 30, 31;,
       3;30, 75, 31;,
       3;30, 29, 75;,
       3;29, 65, 75;,
       3;29, 27, 65;,
       3;76, 77, 78;,
       3;79, 80, 76;,
       3;80, 77, 76;,
       3;80, 81, 77;,
       3;47, 46, 79;,
       3;46, 80, 79;,
       3;46, 45, 80;,
       3;45, 81, 80;,
       3;45, 39, 81;,
       3;82, 76, 78;,
       3;83, 84, 82;,
       3;84, 76, 82;,
       3;84, 79, 76;,
       3;55, 54, 83;,
       3;54, 84, 83;,
       3;54, 53, 84;,
       3;53, 79, 84;,
       3;53, 47, 79;,
       3;85, 82, 78;,
       3;86, 87, 85;,
       3;87, 82, 85;,
       3;87, 83, 82;,
       3;63, 62, 86;,
       3;62, 87, 86;,
       3;62, 61, 87;,
       3;61, 83, 87;,
       3;61, 55, 83;,
       3;88, 85, 78;,
       3;89, 90, 88;,
       3;90, 85, 88;,
       3;90, 86, 85;,
       3;36, 70, 89;,
       3;70, 90, 89;,
       3;70, 69, 90;,
       3;69, 86, 90;,
       3;69, 63, 86;,
       3;77, 88, 78;,
       3;81, 91, 77;,
       3;91, 88, 77;,
       3;91, 89, 88;,
       3;39, 38, 81;,
       3;38, 91, 81;,
       3;38, 37, 91;,
       3;37, 89, 91;,
       3;37, 36, 89;;

      MeshNormals {
       92;
       -0.241252; -0.322868; -0.915180;,
       -0.609963; -0.252069; -0.751270;,
       -0.407870; -0.010453; -0.912980;,
       -0.024973; -0.617254; -0.786368;,
       -0.418098; -0.601586; -0.680653;,
       -0.742885; -0.479402; -0.467222;,
       0.179621; -0.808211; -0.560831;,
       -0.166690; -0.860785; -0.480900;,
       -0.510765; -0.794716; -0.327942;,
       -0.766724; -0.626496; -0.140136;,
       -0.664055; 0.153541; -0.731749;,
       -0.869757; -0.092664; -0.484703;,
       -0.848208; 0.310356; -0.429211;,
       -0.939580; -0.311533; -0.141902;,
       -0.990059; 0.066976; -0.123685;,
       -0.905560; 0.414555; -0.090030;,
       -0.328776; 0.333422; -0.883593;,
       -0.569380; 0.532786; -0.626056;,
       -0.195390; 0.660601; -0.724865;,
       -0.704874; 0.660792; -0.257889;,
       -0.391996; 0.828655; -0.399588;,
       -0.045021; 0.876245; -0.479759;,
       -0.067469; 0.038985; -0.996959;,
       0.067922; 0.410413; -0.909367;,
       0.313398; 0.087306; -0.945600;,
       0.213073; 0.712470; -0.668570;,
       0.456921; 0.437707; -0.774362;,
       0.625658; 0.120534; -0.770729;,
       0.161420; -0.290668; -0.943110;,
       0.545689; -0.227916; -0.806398;,
       0.383518; -0.565592; -0.730082;,
       0.492664; -0.776593; -0.392665;,
       0.152605; -0.959038; -0.238656;,
       0.758888; -0.633637; -0.150314;,
       0.472151; -0.881516; -0.001750;,
       0.106476; -0.983663; 0.145155;,
       0.905560; -0.414555; 0.090031;,
       0.704874; -0.660792; 0.257889;,
       0.391996; -0.828655; 0.399588;,
       0.045021; -0.876245; 0.479759;,
       -0.564859; -0.821272; 0.080291;,
       -0.829890; -0.522639; 0.195273;,
       -0.267489; -0.911855; 0.311401;,
       -0.568269; -0.681736; 0.460767;,
       -0.775959; -0.338918; 0.531998;,
       -0.213073; -0.712470; 0.668570;,
       -0.456921; -0.437707; 0.774362;,
       -0.625658; -0.120534; 0.770729;,
       -0.935147; 0.266626; 0.233260;,
       -0.758888; 0.633637; 0.150314;,
       -0.830823; 0.072473; 0.551798;,
       -0.720907; 0.462805; 0.515853;,
       -0.492664; 0.776593; 0.392665;,
       -0.545689; 0.227916; 0.806398;,
       -0.383518; 0.565592; 0.730082;,
       -0.179621; 0.808211; 0.560831;,
       -0.106476; 0.983663; -0.145155;,
       0.267489; 0.911855; -0.311401;,
       -0.152606; 0.959038; 0.238656;,
       0.225178; 0.970391; 0.087381;,
       0.564859; 0.821272; -0.080291;,
       0.166690; 0.860785; 0.480900;,
       0.510765; 0.794716; 0.327942;,
       0.766724; 0.626496; 0.140136;,
       0.775959; 0.338918; -0.531998;,
       0.830823; -0.072472; -0.551798;,
       0.829890; 0.522639; -0.195273;,
       0.962529; 0.139555; -0.232514;,
       0.935147; -0.266626; -0.233260;,
       0.939580; 0.311533; 0.141902;,
       0.990059; -0.066976; 0.123685;,
       -0.225178; -0.970391; -0.087381;,
       -0.962529; -0.139555; 0.232514;,
       -0.472151; 0.881516; 0.001750;,
       0.568269; 0.681736; -0.460767;,
       0.720907; -0.462805; -0.515853;,
       0.067469; -0.038985; 0.996959;,
       0.328776; -0.333422; 0.883593;,
       0.407870; 0.010453; 0.912980;,
       -0.313398; -0.087306; 0.945600;,
       -0.067922; -0.410412; 0.909367;,
       0.195390; -0.660601; 0.724865;,
       0.241252; 0.322868; 0.915180;,
       0.024973; 0.617254; 0.786368;,
       -0.161420; 0.290668; 0.943110;,
       0.609963; 0.252069; 0.751270;,
       0.742885; 0.479401; 0.467222;,
       0.418098; 0.601586; 0.680653;,
       0.664055; -0.153541; 0.731749;,
       0.848208; -0.310356; 0.429211;,
       0.869757; 0.092663; 0.484703;,
       0.569380; -0.532786; 0.626056;;
       180;
       3;0, 1, 2;,
       3;3, 4, 0;,
       3;4, 1, 0;,
       3;4, 5, 1;,
       3;6, 7, 3;,
       3;7, 4, 3;,
       3;7, 8, 4;,
       3;8, 5, 4;,
       3;8, 9, 5;,
       3;1, 10, 2;,
       3;5, 11, 1;,
       3;11, 10, 1;,
       3;11, 12, 10;,
       3;9, 13, 5;,
       3;13, 11, 5;,
       3;13, 14, 11;,
       3;14, 12, 11;,
       3;14, 15, 12;,
       3;10, 16, 2;,
       3;12, 17, 10;,
       3;17, 16, 10;,
       3;17, 18, 16;,
       3;15, 19, 12;,
       3;19, 17, 12;,
       3;19, 20, 17;,
       3;20, 18, 17;,
       3;20, 21, 18;,
       3;16, 22, 2;,
       3;18, 23, 16;,
       3;23, 22, 16;,
       3;23, 24, 22;,
       3;21, 25, 18;,
       3;25, 23, 18;,
       3;25, 26, 23;,
       3;26, 24, 23;,
       3;26, 27, 24;,
       3;22, 0, 2;,
       3;24, 28, 22;,
       3;28, 0, 22;,
       3;28, 3, 0;,
       3;27, 29, 24;,
       3;29, 28, 24;,
       3;29, 30, 28;,
       3;30, 3, 28;,
       3;30, 6, 3;,
       3;31, 32, 6;,
       3;33, 34, 31;,
       3;34, 32, 31;,
       3;34, 35, 32;,
       3;36, 37, 33;,
       3;37, 34, 33;,
       3;37, 38, 34;,
       3;38, 35, 34;,
       3;38, 39, 35;,
       3;40, 41, 9;,
       3;42, 43, 40;,
       3;43, 41, 40;,
       3;43, 44, 41;,
       3;39, 45, 42;,
       3;45, 43, 42;,
       3;45, 46, 43;,
       3;46, 44, 43;,
       3;46, 47, 44;,
       3;48, 49, 15;,
       3;50, 51, 48;,
       3;51, 49, 48;,
       3;51, 52, 49;,
       3;47, 53, 50;,
       3;53, 51, 50;,
       3;53, 54, 51;,
       3;54, 52, 51;,
       3;54, 55, 52;,
       3;56, 57, 21;,
       3;58, 59, 56;,
       3;59, 57, 56;,
       3;59, 60, 57;,
       3;55, 61, 58;,
       3;61, 59, 58;,
       3;61, 62, 59;,
       3;62, 60, 59;,
       3;62, 63, 60;,
       3;64, 65, 27;,
       3;66, 67, 64;,
       3;67, 65, 64;,
       3;67, 68, 65;,
       3;63, 69, 66;,
       3;69, 67, 66;,
       3;69, 70, 67;,
       3;70, 68, 67;,
       3;70, 36, 68;,
       3;42, 35, 39;,
       3;40, 71, 42;,
       3;71, 35, 42;,
       3;71, 32, 35;,
       3;9, 8, 40;,
       3;8, 71, 40;,
       3;8, 7, 71;,
       3;7, 32, 71;,
       3;7, 6, 32;,
       3;50, 44, 47;,
       3;48, 72, 50;,
       3;72, 44, 50;,
       3;72, 41, 44;,
       3;15, 14, 48;,
       3;14, 72, 48;,
       3;14, 13, 72;,
       3;13, 41, 72;,
       3;13, 9, 41;,
       3;58, 52, 55;,
       3;56, 73, 58;,
       3;73, 52, 58;,
       3;73, 49, 52;,
       3;21, 20, 56;,
       3;20, 73, 56;,
       3;20, 19, 73;,
       3;19, 49, 73;,
       3;19, 15, 49;,
       3;66, 60, 63;,
       3;64, 74, 66;,
       3;74, 60, 66;,
       3;74, 57, 60;,
       3;27, 26, 64;,
       3;26, 74, 64;,
       3;26, 25, 74;,
       3;25, 57, 74;,
       3;25, 21, 57;,
       3;33, 68, 36;,
       3;31, 75, 33;,
       3;75, 68, 33;,
       3;75, 65, 68;,
       3;6, 30, 31;,
       3;30, 75, 31;,
       3;30, 29, 75;,
       3;29, 65, 75;,
       3;29, 27, 65;,
       3;76, 77, 78;,
       3;79, 80, 76;,
       3;80, 77, 76;,
       3;80, 81, 77;,
       3;47, 46, 79;,
       3;46, 80, 79;,
       3;46, 45, 80;,
       3;45, 81, 80;,
       3;45, 39, 81;,
       3;82, 76, 78;,
       3;83, 84, 82;,
       3;84, 76, 82;,
       3;84, 79, 76;,
       3;55, 54, 83;,
       3;54, 84, 83;,
       3;54, 53, 84;,
       3;53, 79, 84;,
       3;53, 47, 79;,
       3;85, 82, 78;,
       3;86, 87, 85;,
       3;87, 82, 85;,
       3;87, 83, 82;,
       3;63, 62, 86;,
       3;62, 87, 86;,
       3;62, 61, 87;,
       3;61, 83, 87;,
       3;61, 55, 83;,
       3;88, 85, 78;,
       3;89, 90, 88;,
       3;90, 85, 88;,
       3;90, 86, 85;,
       3;36, 70, 89;,
       3;70, 90, 89;,
       3;70, 69, 90;,
       3;69, 86, 90;,
       3;69, 63, 86;,
       3;77, 88, 78;,
       3;81, 91, 77;,
       3;91, 88, 77;,
       3;91, 89, 88;,
       3;39, 38, 81;,
       3;38, 91, 81;,
       3;38, 37, 91;,
       3;37, 89, 91;,
       3;37, 36, 89;;
      }

      MeshTextureCoords {
       92;
       0.653533; 0.610627;,
       0.536345; 0.432649;,
       0.469185; 0.606412;,
       0.817206; 0.599946;,
       0.726366; 0.428086;,
       0.598611; 0.267955;,
       0.938165; 0.575805;,
       0.889161; 0.409623;,
       0.787754; 0.255610;,
       0.647598; 0.134507;,
       0.329212; 0.484904;,
       0.397028; 0.300418;,
       0.212237; 0.365429;,
       0.463433; 0.129887;,
       0.284192; 0.175106;,
       0.134011; 0.264075;,
       0.318384; 0.695179;,
       0.175694; 0.567009;,
       0.192039; 0.757662;,
       0.066231; 0.437636;,
       0.056861; 0.619595;,
       0.107164; 0.785449;,
       0.518825; 0.772880;,
       0.368241; 0.859440;,
       0.565931; 0.902601;,
       0.246475; 0.907570;,
       0.419925; 0.974808;,
       0.604158; 0.978109;,
       0.708575; 0.773581;,
       0.755074; 0.890257;,
       0.871642; 0.749854;,
       0.977240; 0.652179;,
       0.988068; 0.441905;,
       0.952051; 0.708061;,
       1.003178; 0.513005;,
       0.972248; 0.315828;,
       0.865989; 0.735925;,
       0.933769; 0.562364;,
       0.943139; 0.380405;,
       0.892836; 0.214551;,
       0.769473; 0.109914;,
       0.569031; 0.032213;,
       0.855060; 0.137849;,
       0.683039; 0.026795;,
       0.481169; -0.007090;,
       0.753525; 0.092430;,
       0.580075; 0.025192;,
       0.395842; 0.021891;,
       0.182657; 0.129687;,
       0.047950; 0.291939;,
       0.274036; 0.045165;,
       0.117183; 0.169548;,
       0.022760; 0.347821;,
       0.244926; 0.109743;,
       0.128358; 0.250146;,
       0.061835; 0.424195;,
       0.027752; 0.684172;,
       0.144939; 0.862151;,
       0.011932; 0.558095;,
       0.087604; 0.743985;,
       0.230527; 0.890086;,
       0.110839; 0.590377;,
       0.212246; 0.744390;,
       0.352402; 0.865493;,
       0.518831; 1.007090;,
       0.725965; 0.954835;,
       0.430969; 0.967787;,
       0.635178; 0.956253;,
       0.817343; 0.870313;,
       0.536567; 0.870113;,
       0.715808; 0.824894;,
       0.912396; 0.256015;,
       0.364822; 0.043748;,
       -0.003178; 0.486995;,
       0.316961; 0.973205;,
       0.882817; 0.830452;,
       0.481175; 0.227120;,
       0.681616; 0.304822;,
       0.530815; 0.393588;,
       0.434069; 0.097399;,
       0.631759; 0.140560;,
       0.807961; 0.242338;,
       0.346467; 0.389373;,
       0.182794; 0.400055;,
       0.291425; 0.226419;,
       0.463655; 0.567351;,
       0.401389; 0.732045;,
       0.273634; 0.571914;,
       0.670788; 0.515096;,
       0.787763; 0.634571;,
       0.602972; 0.699582;,
       0.824306; 0.432991;;
      }

      MeshMaterialList {
       1;
       180;
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0;

       Material PDX9___Default {
        1.000000; 1.000000; 1.000000; 1.000000;;
        128.000000;
        0.000000; 0.000000; 0.000000;;
        0.000000; 0.000000; 0.000000;;

        TextureFilename {
         "starneb2.jpg";
        }
       }

      }

      XSkinMeshHeader {
       1;
       1;
       1;
      }

      SkinWeights {
       "Body";
       92;
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,
       8,
       9,
       10,
       11,
       12,
       13,
       14,
       15,
       16,
       17,
       18,
       19,
       20,
       21,
       22,
       23,
       24,
       25,
       26,
       27,
       28,
       29,
       30,
       31,
       32,
       33,
       34,
       35,
       36,
       37,
       38,
       39,
       40,
       41,
       42,
       43,
       44,
       45,
       46,
       47,
       48,
       49,
       50,
       51,
       52,
       53,
       54,
       55,
       56,
       57,
       58,
       59,
       60,
       61,
       62,
       63,
       64,
       65,
       66,
       67,
       68,
       69,
       70,
       71,
       72,
       73,
       74,
       75,
       76,
       77,
       78,
       79,
       80,
       81,
       82,
       83,
       84,
       85,
       86,
       87,
       88,
       89,
       90,
       91;
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000;
          1.000000, -0.000000, 0.000000, 0.000000,
          -0.000000, 1.000000, -0.000000, 0.000000,
          0.000000, -0.000000, 1.000000, 0.000000,
          -0.000000, -0.000000, -0.000000, 1.000000;;
      }


     }
   }
