// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    float RGB_ttl;
    float RGB_flt_avg;
    int RGB_int_avg;

    //FOR EACH PX
    for (int r = 0; r <= height; r++)
    {
        for (int c = 0; c <= width; c++)
        {
            //OBTAIN AVG OF PIXEL RGB COLORS
            RGB_ttl = ((image[r][c].rgbtBlue + image[r][c].rgbtGreen + image[r][c].rgbtRed));
            RGB_flt_avg = (RGB_ttl / 3);
            RGB_int_avg = (RGB_flt_avg + 0.5);

            //ASSIGN THIS AVG TO EACH COLOR OF THE PIXEL
            image[r][c].rgbtBlue =  RGB_int_avg;
            image[r][c].rgbtGreen =  RGB_int_avg;
            image[r][c].rgbtRed =  RGB_int_avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_pixel;

    //FOR EACH PX
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < (width * 0.5); c++)
        {
            //STORE THIS PIXEL IN A TEMP VARIABLE//
            temp_pixel = image[r][c];

            //REPLACE THE PIXEL BY ITS OPPOSITE//
            image[r][c] = image[r][width - 1 - c];

            //REPLACE THE OPPOSITE BY THE STORED PIXEL//
            image[r][width - 1 - c] = temp_pixel;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //CEATE A TEMPORARY ARRAY OF THE SIZE OF THE IMAGE, TO STORE MODIFIED PIXELS ON IT//
    RGBTRIPLE image_new[height][width];

    //MIDDLE PIXELS
    //FOR EACH PX
    for (int r = 1; r < height - 1; r++)
    {
        for (int c = 1; c < width - 1; c++)
        {
            float RGB_ttl_R = 0, RGB_ttl_G = 0, RGB_ttl_B = 0;
            
            //OBTAIN TOTAL OF EACH OF RGB COLORS OF THAT PIXEL AND THOSE AROUND IT
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    RGB_ttl_R += (image[r + x][c + y].rgbtRed);
                    RGB_ttl_G += (image[r + x][c + y].rgbtGreen);
                    RGB_ttl_B += (image[r + x][c + y].rgbtBlue);
                }
            }   
            
            float Red_avg = (RGB_ttl_R / 9);
            float Green_avg = (RGB_ttl_G / 9);
            float Blue_avg = (RGB_ttl_B / 9);
            
            image_new[r][c].rgbtRed = (Red_avg + 0.5);
            image_new[r][c].rgbtGreen = (Green_avg + 0.5);
            image_new[r][c].rgbtBlue = (Blue_avg + 0.5);

        }
    }

    //PROCESS EDGES//
    //TOP ROW//
    for (int c = 1; c < width - 1; c++)
    {
        int r = 0;
        float RGB_ttl_R = 0, RGB_ttl_G = 0, RGB_ttl_B = 0;
        
        //OBTAIN TOTAL OF EACH OF RGB COLORS OF THAT PIXEL AND THOSE AROUND IT
        for (int x = 0; x < 2; x++)
        {
            for (int y = -1; y < 2; y++)
            {
                RGB_ttl_R += (image[r + x][c + y].rgbtRed);
                RGB_ttl_G += (image[r + x][c + y].rgbtGreen);
                RGB_ttl_B += (image[r + x][c + y].rgbtBlue);
            }
        }   
        
        float Red_avg = (RGB_ttl_R / 6);
        float Green_avg = (RGB_ttl_G / 6);
        float Blue_avg = (RGB_ttl_B / 6);
        
        image_new[r][c].rgbtRed = (Red_avg + 0.5);
        image_new[r][c].rgbtGreen = (Green_avg + 0.5);
        image_new[r][c].rgbtBlue = (Blue_avg + 0.5);
        
    }

    //BOT ROW//
    for (int c = 1; c < width - 1; c++)
    {
        int r = (height - 1);
        float RGB_ttl_R = 0, RGB_ttl_G = 0, RGB_ttl_B = 0;
        
        //OBTAIN TOTAL OF EACH OF RGB COLORS OF THAT PIXEL AND THOSE AROUND IT
        for (int x = -1; x < 1; x++)
        {
            for (int y = -1; y < 2; y++)
            {
                RGB_ttl_R += (image[r + x][c + y].rgbtRed);
                RGB_ttl_G += (image[r + x][c + y].rgbtGreen);
                RGB_ttl_B += (image[r + x][c + y].rgbtBlue);
            }
        }   
        
        float Red_avg = (RGB_ttl_R / 6);
        float Green_avg = (RGB_ttl_G / 6);
        float Blue_avg = (RGB_ttl_B / 6);
        
        image_new[r][c].rgbtRed = (Red_avg + 0.5);
        image_new[r][c].rgbtGreen = (Green_avg + 0.5);
        image_new[r][c].rgbtBlue = (Blue_avg + 0.5);
        
    }

    //LEFT ROW//
    for (int r = 1; r < height - 1; r++)
    {
        int c = 0;
        
        float RGB_ttl_R = 0, RGB_ttl_G = 0, RGB_ttl_B = 0;
        
        //OBTAIN TOTAL OF EACH OF RGB COLORS OF THAT PIXEL AND THOSE AROUND IT
        for (int x = -1; x < 2; x++)
        {
            for (int y = 0; y < 2; y++)
            {
                RGB_ttl_R += (image[r + x][c + y].rgbtRed);
                RGB_ttl_G += (image[r + x][c + y].rgbtGreen);
                RGB_ttl_B += (image[r + x][c + y].rgbtBlue);
            }
        }   
        
        float Red_avg = (RGB_ttl_R / 6);
        float Green_avg = (RGB_ttl_G / 6);
        float Blue_avg = (RGB_ttl_B / 6);
        
        image_new[r][c].rgbtRed = (Red_avg + 0.5);
        image_new[r][c].rgbtGreen = (Green_avg + 0.5);
        image_new[r][c].rgbtBlue = (Blue_avg + 0.5);
        
    }

    //RIGHT ROW
    for (int r = 1; r < height - 1; r++)
    {
        int c = (width - 1);
        
        float RGB_ttl_R = 0, RGB_ttl_G = 0, RGB_ttl_B = 0;
        
        //OBTAIN TOTAL OF EACH OF RGB COLORS OF THAT PIXEL AND THOSE AROUND IT
        for (int x = -1; x < 2; x++)
        {
            for (int y = -1; y < 1; y++)
            {
                RGB_ttl_R += (image[r + x][c + y].rgbtRed);
                RGB_ttl_G += (image[r + x][c + y].rgbtGreen);
                RGB_ttl_B += (image[r + x][c + y].rgbtBlue);
            }
        }   
        
        float Red_avg = (RGB_ttl_R / 6);
        float Green_avg = (RGB_ttl_G / 6);
        float Blue_avg = (RGB_ttl_B / 6);
        
        image_new[r][c].rgbtRed = (Red_avg + 0.5);
        image_new[r][c].rgbtGreen = (Green_avg + 0.5);
        image_new[r][c].rgbtBlue = (Blue_avg + 0.5);
    }
        

//PROCESS CORNERS//

    //TOP LEFT//
    int c = 0, r = 0;
    float RGB_ttl_R = 0, RGB_ttl_G = 0, RGB_ttl_B = 0;
    
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            RGB_ttl_R += (image[r + x][c + y].rgbtRed);
            RGB_ttl_G += (image[r + x][c + y].rgbtGreen);
            RGB_ttl_B += (image[r + x][c + y].rgbtBlue);
        }
    }   
    
    float Red_avg = (RGB_ttl_R / 4);
    float Green_avg = (RGB_ttl_G / 4);
    float Blue_avg = (RGB_ttl_B / 4);
    
    image_new[r][c].rgbtRed = (Red_avg + 0.5);
    image_new[r][c].rgbtGreen = (Green_avg + 0.5);
    image_new[r][c].rgbtBlue = (Blue_avg + 0.5);
    
    //BOT LEFT//
    c = 0, r = (height - 1);
    RGB_ttl_R = 0, RGB_ttl_G = 0, RGB_ttl_B = 0;
    
    for (int x = -1; x < 1; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            RGB_ttl_R += (image[r + x][c + y].rgbtRed);
            RGB_ttl_G += (image[r + x][c + y].rgbtGreen);
            RGB_ttl_B += (image[r + x][c + y].rgbtBlue);
        }
    }   
    
    Red_avg = (RGB_ttl_R / 4);
    Green_avg = (RGB_ttl_G / 4);
    Blue_avg = (RGB_ttl_B / 4);
    
    image_new[r][c].rgbtRed = (Red_avg + 0.5);
    image_new[r][c].rgbtGreen = (Green_avg + 0.5);
    image_new[r][c].rgbtBlue = (Blue_avg + 0.5);
    
    //BOT RIGHT//
    c = (width - 1), r = (height - 1);
    RGB_ttl_R = 0, RGB_ttl_G = 0, RGB_ttl_B = 0;
    
    for (int x = -1; x < 1; x++)
    {
        for (int y = -1; y < 1; y++)
        {
            RGB_ttl_R += (image[r + x][c + y].rgbtRed);
            RGB_ttl_G += (image[r + x][c + y].rgbtGreen);
            RGB_ttl_B += (image[r + x][c + y].rgbtBlue);
        }
    }   
    
    Red_avg = (RGB_ttl_R / 4);
    Green_avg = (RGB_ttl_G / 4);
    Blue_avg = (RGB_ttl_B / 4);
    
    image_new[r][c].rgbtRed = (Red_avg + 0.5);
    image_new[r][c].rgbtGreen = (Green_avg + 0.5);
    image_new[r][c].rgbtBlue = (Blue_avg + 0.5);
    
    
    //TOP RIGHT//
    c = (width - 1), r = 0;
    RGB_ttl_R = 0, RGB_ttl_G = 0, RGB_ttl_B = 0;
    
    for (int x = 0; x < 2; x++)
    {
        for (int y = -1; y < 1; y++)
        {
            RGB_ttl_R += (image[r + x][c + y].rgbtRed);
            RGB_ttl_G += (image[r + x][c + y].rgbtGreen);
            RGB_ttl_B += (image[r + x][c + y].rgbtBlue);
        }
    }   
    
    Red_avg = (RGB_ttl_R / 4);
    Green_avg = (RGB_ttl_G / 4);
    Blue_avg = (RGB_ttl_B / 4);
    
    image_new[r][c].rgbtRed = (Red_avg + 0.5);
    image_new[r][c].rgbtGreen = (Green_avg + 0.5);
    image_new[r][c].rgbtBlue = (Blue_avg + 0.5);
            
            
    for (r = 0; r < height; r++)
    {
        for (c = 0; c < width; c++)
        {
            image[r][c] = image_new[r][c];

        }

    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //MAKE AN ARRAY THAT IS SIZE OF ORIGINAL PLUS 1 EXTRA PX PER EACH SIDE
    RGBTRIPLE image_edged[height + 2][width + 2];
    //POPULATE IT WITH ONLY BLACK PIXELS
    for (int r = 0; r <= height + 1; r++)
    {
        for (int c = 0; c <= width + 1; c++)
        {
            image_edged[r][c].rgbtRed = 0;
            image_edged[r][c].rgbtGreen = 0;
            image_edged[r][c].rgbtBlue = 0;
        }
    }
    //COPY ORIGINAL IMAGE ARRAY NEW ARRAY, BUT LEAVE 1 BLACK PX MARGIN
    for (int r = 1; r < height + 1; r++)
    {
        for (int c = 1; c < width + 1; c++)
        {
            image_edged[r][c] = image[r - 1][c - 1];
        }
    }
    //DECLARE SOBEL MATRIXES Gx AND Gy
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    //FOR EACH PIXEL IN OUR IMAGE WITH BLACK BORDERS, EXCLUDING THE PIXELS ON THE BORDERS
    for (int r = 1; r <= height + 1; r++)
    {
        for (int c = 1; c <= width + 1; c++)
        {
            int GxBttl = 0, GxGttl = 0, GxRttl = 0;
            int GyGttl = 0, GyRttl = 0, GyBttl = 0;
            float newBchan_val;
            float newGchan_val;
            float newRchan_val;
            //FOR EACH OF THE 9 POSITIONS OF/ARROUND THIS PIXEL//
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    //STORE THE TOTAL OF EACH COLOR * SOBEL INDEX OF THE 9 POSITION.
                    GxRttl += (image_edged[r + x][c + y].rgbtRed * Gx[x + 1][y + 1]);
                    GxBttl += (image_edged[r + x][c + y].rgbtBlue * Gx[x + 1][y + 1]);
                    GxGttl += (image_edged[r + x][c + y].rgbtGreen * Gx[x + 1][y + 1]);
                    
                    GyRttl += (image_edged[r + x][c + y].rgbtRed * Gy[x + 1][y + 1]);
                    GyBttl += (image_edged[r + x][c + y].rgbtBlue * Gy[x + 1][y + 1]);
                    GyGttl += (image_edged[r + x][c + y].rgbtGreen * Gy[x + 1][y + 1]);
                }
            }
            //COMPUTE EACH NEW CHANNEL VALUE FOR THE PIXEL 
            newRchan_val = sqrt((pow(GxRttl, 2)) + (pow(GyRttl, 2)));
            newGchan_val = sqrt((pow(GxGttl, 2)) + (pow(GyGttl, 2)));
            newBchan_val = sqrt((pow(GxBttl, 2)) + (pow(GyBttl, 2)));
            //IF VALUE EXCEEDS, CAP AT 255
            if (newRchan_val > 255)
            {
                newRchan_val = 255;
            }
            if (newGchan_val > 255)
            {
                newGchan_val = 255;
            }
            if (newBchan_val > 255)
            {
                newBchan_val = 255;
            }
            //ASSIGN THE ALTERED VALUES FOR EACH CHANNEL TO THE CORRESPONDING PIXEL IN THE ORIGINAL IMAGE
            image[r - 1][c - 1].rgbtRed = newRchan_val + 0.5;
            image[r - 1][c - 1].rgbtGreen = newGchan_val + 0.5;
            image[r - 1][c - 1].rgbtBlue = newBchan_val + 0.5;
            
        }
    }
    return;
}