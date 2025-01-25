uniform sampler2D texture;       // The input texture
uniform float height;

// Normalizing function
float normalize(float t_val, int t_min, int t_max)
{
    return (t_val - t_min) / (t_max - t_min);
}

void main()
{
    vec2 uv = gl_TexCoord[0].xy;
    int midWayPoint = 10000;
    int endPoint = 20000;

    float brightnessStrength = 0.2;
    float darknessStrength = 0.5;

    float brightnessLevel = normalize(height, midWayPoint, endPoint) * brightnessStrength;
    float darknessLevel = -(normalize(height, midWayPoint, 0) * darknessStrength);

    vec4 brightness;

    if (height <= midWayPoint)
    {
        brightness = vec4(darknessLevel, darknessLevel, darknessLevel, 0.0);
    }
    else
    {
        brightness = vec4(brightnessLevel, brightnessLevel, brightnessLevel, 0.0);
    }


    // Sample the distorted texture
    vec4 pixel = texture2D(texture, uv);

    // Output the final color
    gl_FragColor = pixel + brightness;
}
