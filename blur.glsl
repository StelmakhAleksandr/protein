// automatically generated by GenerateGaussFunctionCode in GaussianBlur.h                                                                                            
vec3 GaussianBlur( sampler2D tex0, vec2 centreUV, vec2 halfPixelOffset, vec2 pixelOffset )                                                                           
{                                                                                                                                                                    
    vec3 colOut = vec3( 0, 0, 0 );                                                                                                                                   
                                                                                                                                                                     
    ////////////////////////////////////////////////;
    // Kernel width 7 x 7
    //
    const int stepCount = 2;
    //
    const float gWeights[stepCount] ={
       0.44908,
       0.05092
    };
    const float gOffsets[stepCount] ={
       0.53805,
       2.06278
    };
    ////////////////////////////////////////////////;

    for( int i = 0; i < stepCount; i++ )                                                                                                                             
    {                                                                                                                                                                
        vec2 texCoordOffset = gOffsets[i] * pixelOffset;                                                                                                           
        vec3 col = texture( tex0, centreUV + texCoordOffset ).xyz + 
                   texture( tex0, centreUV � texCoordOffset ).xyz;                                                
        colOut += gWeights[i] * col;                                                                                                                               
    }                                                                                                                                                                

    return colOut;
}                       