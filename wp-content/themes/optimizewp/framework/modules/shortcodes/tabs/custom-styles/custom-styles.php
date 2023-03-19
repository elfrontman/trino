<?php
if(!function_exists('optimize_mikado_tabs_typography_styles')){
	function optimize_mikado_tabs_typography_styles(){
		$selector = '.mkdf-tabs .mkdf-tabs-nav li a';
		$tabs_tipography_array = array();
		$font_family = optimize_mikado_options()->getOptionValue('tabs_font_family');
		
		if(optimize_mikado_is_font_option_valid($font_family)){
			$tabs_tipography_array['font-family'] = optimize_mikado_is_font_option_valid($font_family);
		}
		
		$text_transform = optimize_mikado_options()->getOptionValue('tabs_text_transform');
        if(!empty($text_transform)) {
            $tabs_tipography_array['text-transform'] = $text_transform;
        }

        $font_style = optimize_mikado_options()->getOptionValue('tabs_font_style');
        if(!empty($font_style)) {
            $tabs_tipography_array['font-style'] = $font_style;
        }

        $letter_spacing = optimize_mikado_options()->getOptionValue('tabs_letter_spacing');
        if($letter_spacing !== '') {
            $tabs_tipography_array['letter-spacing'] = optimize_mikado_filter_px($letter_spacing).'px';
        }

        $font_weight = optimize_mikado_options()->getOptionValue('tabs_font_weight');
        if(!empty($font_weight)) {
            $tabs_tipography_array['font-weight'] = $font_weight;
        }

        echo optimize_mikado_dynamic_css($selector, $tabs_tipography_array);
	}
	add_action('optimize_mikado_style_dynamic', 'optimize_mikado_tabs_typography_styles');
}

if(!function_exists('optimize_mikado_tabs_inital_color_styles')){
	function optimize_mikado_tabs_inital_color_styles(){
		$selector = '.mkdf-tabs .mkdf-tabs-nav li a';
		$styles = array();
		
		if(optimize_mikado_options()->getOptionValue('tabs_color')) {
            $styles['color'] = optimize_mikado_options()->getOptionValue('tabs_color');
        }
		if(optimize_mikado_options()->getOptionValue('tabs_back_color')) {
            $styles['background-color'] = optimize_mikado_options()->getOptionValue('tabs_back_color');
        }
		if(optimize_mikado_options()->getOptionValue('tabs_border_color')) {
            $styles['border-color'] = optimize_mikado_options()->getOptionValue('tabs_border_color');
        }
		
		echo optimize_mikado_dynamic_css($selector, $styles);
	}
	add_action('optimize_mikado_style_dynamic', 'optimize_mikado_tabs_inital_color_styles');
}
if(!function_exists('optimize_mikado_tabs_active_color_styles')){
	function optimize_mikado_tabs_active_color_styles(){
		$selector = '.mkdf-tabs .mkdf-tabs-nav li.ui-state-active a, .mkdf-tabs .mkdf-tabs-nav li.ui-state-hover a';
		$styles = array();
		
		if(optimize_mikado_options()->getOptionValue('tabs_color_active')) {
            $styles['color'] = optimize_mikado_options()->getOptionValue('tabs_color_active');
        }
		if(optimize_mikado_options()->getOptionValue('tabs_back_color_active')) {
            $styles['background-color'] = optimize_mikado_options()->getOptionValue('tabs_back_color_active');
        }
		if(optimize_mikado_options()->getOptionValue('tabs_border_color_active')) {
            $styles['border-color'] = optimize_mikado_options()->getOptionValue('tabs_border_color_active');
        }
		
		echo optimize_mikado_dynamic_css($selector, $styles);
	}
	add_action('optimize_mikado_style_dynamic', 'optimize_mikado_tabs_active_color_styles');
}