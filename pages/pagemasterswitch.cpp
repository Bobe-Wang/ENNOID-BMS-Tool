/*
    Original copyright 2018 Benjamin Vedder benjamin@vedder.se and the VESC Tool project ( https://github.com/vedderb/vesc_tool )
    Now forked to:
    Danny Bokma github@diebie.nl

    This file is part of BMS Tool.

    ENNOID-BMS Tool is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ENNOID-BMS Tool is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "pagemasterswitch.h"
#include "ui_pagemasterswitch.h"

PageMasterSwitch::PageMasterSwitch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageMasterSwitch)
{
    ui->setupUi(this);
    mDieBieMS = 0;
}

PageMasterSwitch::~PageMasterSwitch()
{
    delete ui;
}

BMSInterface *PageMasterSwitch::bms() const
{
    return mDieBieMS;
}

void PageMasterSwitch::setDieBieMS(BMSInterface *dieBieMS)
{
    mDieBieMS = dieBieMS;

    if (mDieBieMS) {
        ui->dischargeTab->addRowSeparator(tr("Low current output switch"));
        ui->dischargeTab->addParamRow(mDieBieMS->bmsConfig(), "LCUseDischarge");
        ui->dischargeTab->addParamRow(mDieBieMS->bmsConfig(), "LCUsePrecharge");
        ui->dischargeTab->addParamRow(mDieBieMS->bmsConfig(), "minimalPrechargePercentage");
        ui->dischargeTab->addParamRow(mDieBieMS->bmsConfig(), "timeoutLCPreCharge");
        ui->dischargeTab->addParamRow(mDieBieMS->bmsConfig(), "timeoutDischargeRetry");        

        ui->chargeTab->addRowSeparator(tr("General charger switch"));
        ui->chargeTab->addParamRow(mDieBieMS->bmsConfig(), "chargerEnabledThreshold");
        ui->chargeTab->addParamRow(mDieBieMS->bmsConfig(), "timeoutChargerDisconnected");
        ui->chargeTab->addParamRow(mDieBieMS->bmsConfig(), "allowChargingDuringDischarge");
        ui->chargeTab->addParamRow(mDieBieMS->bmsConfig(), "timeoutChargeRetry");
    }
}
