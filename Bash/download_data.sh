#!/bin/bash

# Script to download the data and check its checksum.

curl "http://uu.diva-portal.org/smash/get/diva2:1440955/DATASET01.tar.gz" --output "2016-2019 TList-data.tar.gz" \
&& echo "bcd4dd6581c870244f8a8cde922adc1a5f52477fa6b7180909a0d8a70961f44e6ba6dd41c361ffc556dbade6656f062543b3b16cc5d5cf68181f9471487c42ea  2016-2019 TList-data.tar.gz" > "2016-2019 TList-data.tar.gz.sha512" \
&& sha512sum -c "2016-2019 TList-data.tar.gz.sha512"
