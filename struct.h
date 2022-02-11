#ifndef struct_h
#define struct_h

struct componant_struct{
	int componant_type;
	long int componant_in_connect;
	long int componant_out_connect;
	double componant_value_polar;
    double componant_value_rectangular;
    
};

struct componant_voltage_scource{
    double voltage;
    double angular_frequency;
    double offset; 
	long int voltage_scourc_in_connect;
	long int voltage_scourc_out_connect;
};

#endif