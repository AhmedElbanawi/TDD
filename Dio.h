#ifdef UT_H
typedef struct{
    unsigned char Bit0:1;
    unsigned char Bit1:1;
    unsigned char Bit2:1;
    unsigned char Bit3:1;
    unsigned char Bit4:1;
    unsigned char Bit5:1;
    unsigned char Bit6:1;
    unsigned char Bit7:1;
}BitFiled;
 BitFiled PORTA_DIRECTION; 
BitFiled  PORTA_WRITE_STATE;
BitFiled  PORTA_READ_STATE;
#endif
#define NULL_PTR ((void*)0)
typedef struct Dio Dio_Type;

typedef enum
{
    DIO_PORTA_PIN_0 = 0,
    DIO_PORTA_PIN_1
}Dio_Id_Type;

typedef enum
{
    DIO_CHANNEL_LOW = 0,
    DIO_CHANNEL_High
}Dio_State_type;

struct Dio
{   
    Dio_Id_Type Id;
    void (*SetPinInput)(Dio_Type*self);
    void (*SetPinOutput)(Dio_Type*self);
    void (*SetPinHigh)(Dio_Type*self);
    void (*SetPinLow)(Dio_Type*self);
    void (*SetPinToggle)(Dio_Type*self);
    Dio_State_type (*GetState)(Dio_Type*self);
};
extern Dio_Type Dio_Cfg[1];
