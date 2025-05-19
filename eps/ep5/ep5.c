// For more information on PPM (P3) format, see https://paulbourke.net/dataformats/ppm/.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent an image
struct image
{
    unsigned char ***data; // 3D matrix of unsigned char representing the image (height x width x 3 for RGB)
    int width;             // Width of the image
    int height;            // Height of the image
};

// Typedef the struct image to Image
typedef struct image Image;

/**
 * Loads an image from a (RGB+P3) PPM file.
 *
 * @param filename The path to the PPM file.
 * @param image    A pointer to the Image structure where the loaded image will be stored.
 */
void load_image_ppm(const char *filename, Image *image)
{
    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    // Read the PPM header
    char magic[3];
    int max_value;
    
    // Read the magic number (it must be P3)
    if (fscanf(file, "%2s", magic) != 1 || strcmp(magic, "P3") != 0){
        printf("Identificador inválido, deve ser \"P3\"\n");
        fclose(file);
        return;
    }
    
    // Read the width and height of the image
    if (fscanf(file, "%d", &image->width) != 1){
        printf("Ocorreu um erro ao ler a largura da imagem.\n");
        fclose(file);
        return;
    }
    
    if (fscanf(file, "%d", &image->height) != 1){
        printf("Ocorreu um erro ao ler a largura da imagem.\n");
        fclose(file);
        return;
    }
    
    // Read the maximum pixel value (it must be 255)
    if (fscanf(file, "%d", &max_value) != 1 || max_value != 255){
        printf("Erro: valor máximo do pixel deve ser 255.\n");
        fclose(file);
        return;
    }

    // Allocate memory for the image data
    image->data = (unsigned char ***)malloc(image->height * sizeof(unsigned char **));
    if (image->data == NULL){
        printf("Erro ao alocar memória para os dados da imagem.\n");
        fclose(file);
        return;
    }

    for (int i = 0; i < image->height; i++){
        image->data[i] = (unsigned char **)malloc(image->width * sizeof(unsigned char *));
        if (image->data[i] == NULL){
            printf("Erro ao alocar memória para a linha de dados da imagem.\n");
            // Liberando memória alocada que não será usada devido ao erro
            for (int j = 0; j < i; j++){
                free(image->data[j]);
            }
            free(image->data);
            fclose(file);
            return;
        }

        for (int j = 0; j < image->width; j++){
            image->data[i][j] = (unsigned char *)malloc(3 * sizeof(unsigned char));
            if (image->data[i][j] == NULL){
                printf("Erro ao alocar memória para o pixel da imagem.\n");
                // Liberando memória alocada que não será usada devido ao erro
                for (int k = 0; k < j; k++){
                    free(image->data[i][k]);
                }
                for (int k = 0; k < i; k++){
                    for (int l = 0; l < image->width; l++){
                        free(image->data[k][l]);
                    }
                    free(image->data[k]);
                }
                free(image->data[i]);
                free(image->data);
                fclose(file);
                return;
            }
        }
    }

    // Read the image data
    for (int i = 0; i < image->height; i++)
    {
        for (int j = 0; j < image->width; j++)
        {
            int r, g, b;
            
            // Lendo o RGB
            if (fscanf(file, "%d %d %d", &r, &g, &b) != 3)
            {
                printf("Error reading RGB values at pixel (%d, %d)\n", j, i);
                // Liberando memória alocada
                for (int k = 0; k < image->height; k++)
                {
                    for (int l = 0; l < image->width; l++)
                    {
                        free(image->data[k][l]);
                    }
                    free(image->data[k]);
                }
                free(image->data);
                fclose(file);
                return;
            }

            // Guardando os valores RGB
            image->data[i][j][0] = (unsigned char)r;
            image->data[i][j][1] = (unsigned char)g;
            image->data[i][j][2] = (unsigned char)b;
        }
    }

    // Close the file
    fclose(file);
}
/**
 * Writes the given image to a (RGB+P3) PPM file.
 *
 * @param filename The name of the PPM file to write.
 * @param image The image to write.
 */

void write_image_to_ppm(const char *filename, const Image *image)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf("Error opening file for writing: %s\n", filename);
        return;
    }

    // Write the PPM header
    fprintf(file, "P3\n");                                 // P3 is the magic number for PPM P3 format
    fprintf(file, "%d %d\n", image->width, image->height); // Write the width and height of the image
    fprintf(file, "255\n");                                // Write the maximum pixel value

    // Write the image data
    for (int i = 0; i < image->height; i++)
    {
        for (int j = 0; j < image->width; j++)
        {
            fprintf(file, "%d %d %d", image->data[i][j][0], image->data[i][j][1], image->data[i][j][2]);
            if (j < image->width - 1)
            {
                fprintf(file, " ");
            }
            else
            {
                fprintf(file, "\n");
            }
        }
    }

    // Close the file
    fclose(file);
}

int main()
{
    // Declare an image structure
    Image image;

    // Load the image from the file "input.ppm"
    load_image_ppm("./ep5/input.ppm", &image);

    // Write the image to the file "output.ppm"
    write_image_to_ppm("output.ppm", &image);

    return 0;
}