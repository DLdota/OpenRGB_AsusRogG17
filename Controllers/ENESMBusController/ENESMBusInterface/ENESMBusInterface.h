/*-----------------------------------------*\
|  ENESMBusInterface.h                      |
|                                           |
|  Definitions and types for ENE interface  |
|                                           |
|  Adam Honse (CalcProgrammer1) 11/21/2021  |
\*-----------------------------------------*/

#include <string>

#pragma once

typedef unsigned short	ene_register;
typedef unsigned char	ene_dev_id;
typedef unsigned int    ene_interface_type;

/*-----------------------------------------*\
| Known interface types                     |
\*-----------------------------------------*/
enum
{
    ENE_INTERFACE_TYPE_I2C_SMBUS,
    ENE_INTERFACE_TYPE_SPECTRIX_S40G,
    ENE_INTERFACE_TYPE_ROG_ARION,
};

class ENESMBusInterface
{
public:
    virtual                     ~ENESMBusInterface() = default;

    virtual ene_interface_type  GetInterfaceType() = 0;
    virtual std::string         GetLocation() = 0;
    virtual int                 GetMaxBlock() = 0;
    virtual unsigned char       ENERegisterRead(ene_dev_id dev, ene_register reg) = 0;
    virtual void                ENERegisterWrite(ene_dev_id dev, ene_register reg, unsigned char val) = 0;
    virtual void                ENERegisterWriteBlock(ene_dev_id dev, ene_register reg, unsigned char * data, unsigned char sz) = 0;
};
