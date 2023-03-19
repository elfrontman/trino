<?php 

if(!function_exists('optimize_mikado_accordions_typography_styles')){
	function optimize_mikado_accordions_typography_styles(){
		$selector = '.mkdf-accordion-holder .mkdf-title-holder';
		$styles = array();
		
		$font_family = optimize_mikado_options()->getOptionValue('accordions_font_family');
		if(optimize_mikado_is_font_option_valid($font_family)){
			$styles['font-family'] = optimize_mikado_get_font_option_val($font_family);
		}
		
		$text_transform = optimize_mikado_options()->getOptionValue('accordions_text_transform');
       if(!empty($text_transform)) {
           $styles['text-transform'] = $text_transform;
       }

       $font_style = optimize_mikado_options()->getOptionValue('accordions_font_style');
       if(!empty($font_style)) {
           $styles['font-style'] = $font_style;
       }

       $letter_spacing = optimize_mikado_options()->getOptionValue('accordions_letter_spacing');
       if($letter_spacing !== '') {
           $styles['letter-spacing'] = optimize_mikado_filter_px($letter_spacing).'px';
       }

       $font_weight = optimize_mikado_options()->getOptionValue('accordions_font_weight');
       if(!empty($font_weight)) {
           $styles['font-weight'] = $font_weight;
       }

       echo optimize_mikado_dynamic_css($selector, $styles);
	}
	add_action('optimize_mikado_style_dynamic', 'optimize_mikado_accordions_typography_styles');
}

if(!function_exists('optimize_mikado_accordions_inital_title_color_styles')){
	function optimize_mikado_accordions_inital_title_color_styles(){
		$selector = '.mkdf-accordion-holder.mkdf-initial .mkdf-title-holder';
		$styles = array();
		
		if(optimize_mikado_options()->getOptionValue('accordions_title_color')) {
           $styles['color'] = optimize_mikado_options()->getOptionValue('accordions_title_color');
       }
		echo optimize_mikado_dynamic_css($selector, $styles);
	}
	add_action('optimize_mikado_style_dynamic', 'optimize_mikado_accordions_inital_title_color_styles');
}

if(!function_exists('optimize_mikado_accordions_active_title_color_styles')){
	
	function optimize_mikado_accordions_active_title_color_styles(){
		$selector = array(
			'.mkdf-accordion-holder.mkdf-initial .mkdf-title-holder.ui-state-active',
			'.mkdf-accordion-holder.mkdf-initial .mkdf-title-holder.ui-state-hover'
		);
		$styles = array();
		
		if(optimize_mikado_options()->getOptionValue('accordions_title_color_active')) {
           $styles['color'] = optimize_mikado_options()->getOptionValue('accordions_title_color_active');
       }
		
		echo optimize_mikado_dynamic_css($selector, $styles);
	}
	add_action('optimize_mikado_style_dynamic', 'optimize_mikado_accordions_active_title_color_styles');
}
if(!function_exists('optimize_mikado_accordions_inital_icon_color_styles')){
	
	function optimize_mikado_accordions_inital_icon_color_styles(){
		$selector = '.mkdf-accordion-holder.mkdf-initial .mkdf-title-holder .mkdf-accordion-mark';
		$styles = array();
		
		if(optimize_mikado_options()->getOptionValue('accordions_icon_color')) {
           $styles['color'] = optimize_mikado_options()->getOptionValue('accordions_icon_color');
       }
		if(optimize_mikado_options()->getOptionValue('accordions_icon_back_color')) {
           $styles['background-color'] = optimize_mikado_options()->getOptionValue('accordions_icon_back_color');
       }
		echo optimize_mikado_dynamic_css($selector, $styles);
	}
	add_action('optimize_mikado_style_dynamic', 'optimize_mikado_accordions_inital_icon_color_styles');
}
if(!function_exists('optimize_mikado_accordions_active_icon_color_styles')){
	
	function optimize_mikado_accordions_active_icon_color_styles(){
		$selector = array(
			'.mkdf-accordion-holder.mkdf-initial .mkdf-title-holder.ui-state-active  .mkdf-accordion-mark',
			'.mkdf-accordion-holder.mkdf-initial .mkdf-title-holder.ui-state-hover  .mkdf-accordion-mark'
		);
		$styles = array();
		
		if(optimize_mikado_options()->getOptionValue('accordions_icon_color_active')) {
           $styles['color'] = optimize_mikado_options()->getOptionValue('accordions_icon_color_active');
       }
		if(optimize_mikado_options()->getOptionValue('accordions_icon_back_color_active')) {
           $styles['background-color'] = optimize_mikado_options()->getOptionValue('accordions_icon_back_color_active');
       }
		echo optimize_mikado_dynamic_css($selector, $styles);
	}
	add_action('optimize_mikado_style_dynamic', 'optimize_mikado_accordions_active_icon_color_styles');
}

if(!function_exists('optimize_mikado_boxed_accordions_inital_color_styles')){
	function optimize_mikado_boxed_accordions_inital_color_styles(){
		$selector = '.mkdf-accordion-holder.mkdf-boxed .mkdf-title-holder';
		$styles = array();
		
		if(optimize_mikado_options()->getOptionValue('boxed_accordions_color')) {
           $styles['color'] = optimize_mikado_options()->getOptionValue('boxed_accordions_color');
           echo optimize_mikado_dynamic_css('.mkdf-accordion-holder.mkdf-boxed .mkdf-title-holder .mkdf-accordion-mark', array('color' => optimize_mikado_options()->getOptionValue('boxed_accordions_color')));
       }
		if(optimize_mikado_options()->getOptionValue('boxed_accordions_back_color')) {
           $styles['background-color'] = optimize_mikado_options()->getOptionValue('boxed_accordions_back_color');
       }
		if(optimize_mikado_options()->getOptionValue('boxed_accordions_border_color')) {
           $styles['border-color'] = optimize_mikado_options()->getOptionValue('boxed_accordions_border_color');
       }
		
		echo optimize_mikado_dynamic_css($selector, $styles);
	}
	add_action('optimize_mikado_style_dynamic', 'optimize_mikado_boxed_accordions_inital_color_styles');
}
if(!function_exists('optimize_mikado_boxed_accordions_active_color_styles')){

	function optimize_mikado_boxed_accordions_active_color_styles(){
		$selector = array(
			'.mkdf-accordion-holder.mkdf-boxed.ui-accordion .mkdf-title-holder.ui-state-active',
			'.mkdf-accordion-holder.mkdf-boxed.ui-accordion .mkdf-title-holder.ui-state-hover'
		);
		$selector_icons = array(
			'.mkdf-accordion-holder.mkdf-boxed .mkdf-title-holder.ui-state-active .mkdf-accordion-mark',
			'.mkdf-accordion-holder.mkdf-boxed .mkdf-title-holder.ui-state-hover .mkdf-accordion-mark'
		);
		$styles = array();
		
		if(optimize_mikado_options()->getOptionValue('boxed_accordions_color_active')) {
           $styles['color'] = optimize_mikado_options()->getOptionValue('boxed_accordions_color_active');
           echo optimize_mikado_dynamic_css($selector_icons, array('color' => optimize_mikado_options()->getOptionValue('boxed_accordions_color_active')));
       }
		if(optimize_mikado_options()->getOptionValue('boxed_accordions_back_color_active')) {
           $styles['background-color'] = optimize_mikado_options()->getOptionValue('boxed_accordions_back_color_active');
       }
		if(optimize_mikado_options()->getOptionValue('boxed_accordions_border_color_active')) {
           $styles['border-color'] = optimize_mikado_options()->getOptionValue('boxed_accordions_border_color_active');
       }
		
		echo optimize_mikado_dynamic_css($selector, $styles);
	}
	add_action('optimize_mikado_style_dynamic', 'optimize_mikado_boxed_accordions_active_color_styles');
}