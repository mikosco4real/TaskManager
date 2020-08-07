/**
 * @file Password.cpp
 *
 * @brief This file contains the functions that
 * validate the complexity of the password
 *
 * @author Fernando Quiros
 * @version 1 20/04/2020
 * Contact: fernandoquiros@lsst.org
 *
 */
#include<iostream>
#include<string>

using namespace std;
/**
 * Class PasswordStatus
 *
 * This class contains the main functios that each
 * step of the validation of the password has
 */
class PasswordStatus
{
    bool len, low, up, dig;
public:
    PasswordStatus()
    {
        len = low = up = dig = false;
    }

    /**
     * PasswordStatus::ShowStatus
     * Shows the result of the validation of the password
     * @return -
     */
    void ShowStatus()
    {
        cout << endl << "Password Status:" << endl;
        cout << "Length : " << (len ? "OK" : "Too Short") << endl;
        cout << "Contains Lower Case : " << (low ? "Yes" : "No") << endl;
        cout << "Contains Upper Case : " << (up ? "Yes" : "No") << endl;
        cout << "Contains Digit : " << (dig ? "Yes" : "No") << endl;
    }

    /**
     * checkValidity::ShowStatus
     * Verify if the password has uper case, lower case
     * and digits 
     * @return -
     */
    void checkValidity(string pass)
    {
        int sLen = pass.length();

        len = (sLen >= 8);

        for (int i = 0; i < sLen; i++)
        {
            char c = pass[i];

            if (!low && islower(c)) { low = true; continue; }
            if (!up && isupper(c)) { up = true; continue; }
            if (!dig && isdigit(c)) { dig = true; continue; }
        }
    }
    
    /**
     * checkValidity::IsTotalyValid
     * Return the value of the validation
     * @return bool tru/false
     */
    bool IsTotalyValid()
    {
        return low && up && dig && len;
    }
};