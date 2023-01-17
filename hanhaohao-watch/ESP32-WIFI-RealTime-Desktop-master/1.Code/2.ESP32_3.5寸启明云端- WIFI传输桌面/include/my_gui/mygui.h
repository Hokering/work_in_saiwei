#ifndef _MY_GUI_H_
#define _MY_GUI_H_

/*********************
 *      INCLUDES
 *********************/
#include <lvgl.h>
#include <math.h>

lv_obj_t *tabview;
lv_obj_t * table;

LV_IMG_DECLARE(img_cogwheel_argb);

void lv_ex_tabview_1(void)
{
    //翻页
    /*Create a Tab view object*/
    tabview = lv_tabview_create(lv_scr_act(), NULL);

    /*Add 3 tabs (the tabs are page (lv_page) and can be scrolled*/
    lv_obj_t *tab1 = lv_tabview_add_tab(tabview, "Txt");
    lv_obj_t *tab2 = lv_tabview_add_tab(tabview, "Rtc");
    lv_obj_t *tab3 = lv_tabview_add_tab(tabview, "Img");
    lv_obj_t *tab4 = lv_tabview_add_tab(tabview, "Weather");

    /*Add content to the tabs*/
    lv_obj_t * label = lv_label_create(tab1, NULL);
    lv_label_set_text(label, "This the first tab\n\n"
                             "If the content\n"
                             "of a tab\n"
                             "become too long\n"
                             "the it \n"
                             "automatically\n"
                             "become\n"
                             "scrollable.");

    //----------------------------------------------------------------
    //天气表格
    table = lv_table_create(tab2, NULL);
    lv_table_set_col_cnt(table, 2);
    lv_table_set_row_cnt(table, 7);
    lv_obj_align(table, NULL, LV_ALIGN_CENTER, 0, 0);

    /*Align the price values to the right in the 2nd column*/
    lv_table_set_cell_align(table, 0, 1, LV_LABEL_ALIGN_CENTER);
    lv_table_set_cell_align(table, 1, 1, LV_LABEL_ALIGN_CENTER);
    lv_table_set_cell_align(table, 2, 1, LV_LABEL_ALIGN_CENTER);
    lv_table_set_cell_align(table, 3, 1, LV_LABEL_ALIGN_CENTER);
    lv_table_set_cell_align(table, 4, 1, LV_LABEL_ALIGN_CENTER);
    lv_table_set_cell_align(table, 5, 1, LV_LABEL_ALIGN_CENTER);
    lv_table_set_cell_align(table, 6, 1, LV_LABEL_ALIGN_CENTER);

    lv_table_set_cell_align(table, 0, 0, LV_LABEL_ALIGN_CENTER);
    lv_table_set_cell_align(table, 1, 0, LV_LABEL_ALIGN_CENTER);
    lv_table_set_cell_align(table, 2, 0, LV_LABEL_ALIGN_CENTER);
    lv_table_set_cell_align(table, 3, 0, LV_LABEL_ALIGN_CENTER);
    lv_table_set_cell_align(table, 4, 0, LV_LABEL_ALIGN_CENTER);
    lv_table_set_cell_align(table, 5, 0, LV_LABEL_ALIGN_CENTER);
    lv_table_set_cell_align(table, 6, 0, LV_LABEL_ALIGN_CENTER);

    lv_table_set_cell_type(table, 0, 0, 2);
    lv_table_set_cell_type(table, 0, 1, 2);

    /*Fill the first column*/
    lv_table_set_cell_value(table, 0, 0, "Year");
    lv_table_set_cell_value(table, 1, 0, "Month");
    lv_table_set_cell_value(table, 2, 0, "Day");
    lv_table_set_cell_value(table, 3, 0, "Week");
    lv_table_set_cell_value(table, 4, 0, "Hour");
    lv_table_set_cell_value(table, 5, 0, "Minute");
    lv_table_set_cell_value(table, 6, 0, "Second");

    /*Fill the second column*/
    lv_table_set_cell_value(table, 0, 1, "00");
    lv_table_set_cell_value(table, 1, 1, "00");
    lv_table_set_cell_value(table, 2, 1, "00");
    lv_table_set_cell_value(table, 3, 1, "00");
    lv_table_set_cell_value(table, 4, 1, "00");
    lv_table_set_cell_value(table, 5, 1, "00");
    lv_table_set_cell_value(table, 6, 1, "00");

    //-----------------------------------------------------------
    //图片
    lv_obj_t * img1 = lv_img_create(tab3, NULL);
    lv_img_set_src(img1, &img_cogwheel_argb);
    lv_obj_align(img1, NULL, LV_ALIGN_CENTER, 0, -20);

    lv_obj_t * img2 = lv_img_create(tab3, NULL);
    lv_img_set_src(img2, LV_SYMBOL_OK "Accept"); 
    lv_obj_align(img2, img1, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    //图表
    /*Create a chart*/
    lv_obj_t * chart;
    chart = lv_chart_create(tab4, NULL);
    lv_obj_set_size(chart, 440, 220);
    lv_obj_align(chart, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_chart_set_type(chart, 0x01);   /*Show lines and points too*/

    /*Add two data series*/
    lv_chart_series_t * ser2 = lv_chart_add_series(chart, LV_COLOR_LIME);

    /*Directly set points on 'ser2'*/
    for(float i =0;i<10;i++)
        ser2->points[(int)i] = 50*sin((3.14159265458*i)/3)+50;

    lv_chart_refresh(chart); /*Required after direct set*/
}

#endif /*LV_TEST_CHART_H*/
