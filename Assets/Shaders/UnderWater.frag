uniform sampler2D texture;       // The input texture
uniform sampler2D noiseTexture; // Noise texture
uniform float time;             // Time for animation

void main()
{
    vec2 uv = gl_TexCoord[0].xy;

    float frequency = 0.05;

    // Sample the noise texture (use UV scaling and animation)
    vec2 noiseUV = uv * 0.6 + vec2(cos(time * frequency), sin(time * frequency));
    float n = texture2D(noiseTexture, noiseUV).r;  // Use the red channel as noise

    // Apply the noise to distort UV coordinates
    uv.x += n * 0.02;
    uv.y += n * 0.02;

    float intensity = 0.5;

    vec4 tint = vec4(0.0, 0.0, n * intensity, (n * intensity) / 3.0);

    // Sample the distorted texture
    vec4 pixel = texture2D(texture, uv);

    // Output the final color
    gl_FragColor = pixel + tint;
}
