#pragma once
#include "Contact_Info.h"

class Plant {
public:
	Plant(Contact_Info contact_info_plant) : Info(contact_info_plant) {}

	virtual ~Plant() {}

	Contact_Info Get_Contact_Info() const;

	double Get_Size() const;

	void Set_Size(double size);

	double Get_Growth_Degree() const;

	void Set_Growth_Degree(double growth_degree);

	string Get_Color() const;

	void Set_Color(string plant_color);

	string Get_Plant_Type() const;

	void Set_Plant_Type(string plant_type);

	void Growth();

	void Size_Decline(double size_decline);

private:
	Contact_Info Info;
	double Size = 0;
	double Growth_Degree = 0;
	string Color = "";
	string Plant_Type = "";
};