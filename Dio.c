#include "Dio.h"
void SetPinInput(Dio_Type *self);
void SetPinOutput(Dio_Type *self);
void SetPinHigh(Dio_Type *self);
void SetPinLow(Dio_Type *self);
void SetPinToggle(Dio_Type *self);
void* GetPortAddressForDirection(Dio_Id_Type Id);
void* GetPortAddressForWritingState(Dio_Id_Type Id);
void* GetPortAddressForReadingState(Dio_Id_Type Id);
unsigned char GetPinPostion(Dio_Id_Type Id);

Dio_State_type GetState(Dio_Type*self);
Dio_Type Dio_Cfg[1] =
    {
        {DIO_PORTA_PIN_0,
         SetPinInput,
         SetPinOutput,
         SetPinHigh,
         SetPinLow,
         SetPinToggle,
         GetState
        }
    };
void SetPinInput(Dio_Type *self)
{
}
void SetPinOutput(Dio_Type *self)
{
    if (self != NULL_PTR)
    {
        unsigned char *PortAddress = GetPortAddressForDirection(self->Id);
        unsigned char PinPosition = GetPinPostion(self->Id);
        *PortAddress |= (1 << PinPosition);
    }
    else
    {
        /*Do Nothing*/
    }
}
void SetPinHigh(Dio_Type *self)
{
    if (self != NULL_PTR)
    {
        unsigned char *PortAddress = GetPortAddressForWritingState(self->Id);
        unsigned char PinPosition = GetPinPostion(self->Id);
        *PortAddress |= (1 << PinPosition);
    }
    else
    {
        /*Do Nothing*/
    }
}
void SetPinLow(Dio_Type *self)
{
    if (self != NULL_PTR)
    {
        unsigned char *PortAddress = GetPortAddressForWritingState(self->Id);
        unsigned char PinPosition = GetPinPostion(self->Id);
        *PortAddress &= ~(1 << PinPosition);
    }
    else
    {
        /*Do Nothing*/
    }
}
void SetPinToggle(Dio_Type *self)
{
    if (self != NULL_PTR)
    {
        if(DIO_CHANNEL_High==GetState(self))
        {
            SetPinHigh(self);
        }
        else if(DIO_CHANNEL_LOW==GetState(self))
        {
            SetPinLow(self);
        }
        else
        {
            /*Do Nothing*/
        }
    }
    else
    {
        /*Do Nothing*/
    }
}


Dio_State_type GetState(Dio_Type*self)
{
    Dio_State_type State = DIO_CHANNEL_LOW;
    unsigned char *PortAddress = GetPortAddressForReadingState(self->Id);
    unsigned char PinPosition = GetPinPostion(self->Id);
    if(DIO_CHANNEL_High== (1&(*PortAddress>>PinPosition)))
    {
        State = DIO_CHANNEL_High;
    }
    return State;
}

void* GetPortAddressForDirection(Dio_Id_Type Id)
{
    void* PortAddress[] = {&PORTA_DIRECTION};
    int PortIdx = Id / 8;
    return PortAddress[PortIdx];
}

void* GetPortAddressForWritingState(Dio_Id_Type Id)
{
    void* PortAddress[] = {&PORTA_WRITE_STATE};
    int PortIdx = Id / 8;
    return PortAddress[PortIdx];
}

void* GetPortAddressForReadingState(Dio_Id_Type Id)
{
    void* PortAddress[] = {&PORTA_READ_STATE};
    int PortIdx = Id / 8;
    return PortAddress[PortIdx];
}

unsigned char GetPinPostion(Dio_Id_Type Id)
{
    return (Id%8);
}
