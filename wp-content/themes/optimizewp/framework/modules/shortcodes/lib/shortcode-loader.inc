<?php

namespace Optimize\Modules\Shortcodes\Lib;

use Optimize\Modules\CallToAction\CallToAction;
use Optimize\Modules\Counter\Countdown;
use Optimize\Modules\Counter\Counter;
use Optimize\Modules\ElementsHolder\ElementsHolder;
use Optimize\Modules\ElementsHolderItem\ElementsHolderItem;
use Optimize\Modules\GoogleMap\GoogleMap;
use Optimize\Modules\Separator\Separator;
use Optimize\Modules\PieCharts\PieChartBasic\PieChartBasic;
use Optimize\Modules\PieCharts\PieChartDoughnut\PieChartDoughnut;
use Optimize\Modules\PieCharts\PieChartDoughnut\PieChartPie;
use Optimize\Modules\PieCharts\PieChartWithIcon\PieChartWithIcon;
use Optimize\Modules\Shortcodes\AnimationsHolder\AnimationsHolder;
use Optimize\Modules\Shortcodes\ComparisonPricingTables\ComparisonPricingTable;
use Optimize\Modules\Shortcodes\ComparisonPricingTables\ComparisonPricingTablesHolder;
use Optimize\Modules\Shortcodes\Icon\Icon;
use Optimize\Modules\Shortcodes\IconProgressBar;
use Optimize\Modules\Shortcodes\ImageGallery\ImageGallery;
use Optimize\Modules\Shortcodes\InfoBox\InfoBox;
use Optimize\Modules\Shortcodes\Process\ProcessHolder;
use Optimize\Modules\Shortcodes\Process\ProcessItem;
use Optimize\Modules\Shortcodes\SectionSubtitle\SectionSubtitle;
use Optimize\Modules\Shortcodes\SectionTitle\SectionTitle;
use Optimize\Modules\Shortcodes\VerticalProgressBar\VerticalProgressBar;
use Optimize\Modules\Shortcodes\VideoBanner\VideoBanner;
use Optimize\Modules\SocialShare\SocialShare;
use Optimize\Modules\Team\Team;
use Optimize\Modules\OrderedList\OrderedList;
use Optimize\Modules\UnorderedList\UnorderedList;
use Optimize\Modules\Message\Message;
use Optimize\Modules\ProgressBar\ProgressBar;
use Optimize\Modules\IconListItem\IconListItem;
use Optimize\Modules\Tabs\Tabs;
use Optimize\Modules\Tab\Tab;
use Optimize\Modules\PricingTables\PricingTables;
use Optimize\Modules\PricingTable\PricingTable;
use Optimize\Modules\Accordion\Accordion;
use Optimize\Modules\AccordionTab\AccordionTab;
use Optimize\Modules\BlogList\BlogList;
use Optimize\Modules\Shortcodes\Button\Button;
use Optimize\Modules\Blockquote\Blockquote;
use Optimize\Modules\CustomFont\CustomFont;
use Optimize\Modules\Highlight\Highlight;
use Optimize\Modules\VideoButton\VideoButton;
use Optimize\Modules\Dropcaps\Dropcaps;
use Optimize\Modules\Shortcodes\IconWithText\IconWithText;

/**
 * Class ShortcodeLoader
 */
class ShortcodeLoader {
	/**
	 * @var private instance of current class
	 */
	private static $instance;
	/**
	 * @var array
	 */
	private $loadedShortcodes = array();

	/**
	 * Private constuct because of Singletone
	 */
	private function __construct() {
	}

	/**
	 * Private sleep because of Singletone
	 */
	private function __wakeup() {
	}

	/**
	 * Private clone because of Singletone
	 */
	private function __clone() {
	}

	/**
	 * Returns current instance of class
	 * @return ShortcodeLoader
	 */
	public static function getInstance() {
		if(self::$instance == null) {
			return new self;
		}

		return self::$instance;
	}

	/**
	 * Adds new shortcode. Object that it takes must implement ShortcodeInterface
	 *
	 * @param ShortcodeInterface $shortcode
	 */
	private function addShortcode(ShortcodeInterface $shortcode) {
		if(!array_key_exists($shortcode->getBase(), $this->loadedShortcodes)) {
			$this->loadedShortcodes[$shortcode->getBase()] = $shortcode;
		}
	}

	/**
	 * Adds all shortcodes.
	 *
	 * @see ShortcodeLoader::addShortcode()
	 */
	private function addShortcodes() {
		$this->addShortcode(new ElementsHolder());
		$this->addShortcode(new ElementsHolderItem());
		$this->addShortcode(new Team());
		$this->addShortcode(new Icon());
		$this->addShortcode(new CallToAction());
		$this->addShortcode(new OrderedList());
		$this->addShortcode(new UnorderedList());
		$this->addShortcode(new Message());
		$this->addShortcode(new Counter());
		$this->addShortcode(new Countdown());
		$this->addShortcode(new ProgressBar());
		$this->addShortcode(new IconListItem());
		$this->addShortcode(new Tabs());
		$this->addShortcode(new Tab());
		$this->addShortcode(new PricingTables());
		$this->addShortcode(new PricingTable());
		$this->addShortcode(new PieChartBasic());
		$this->addShortcode(new PieChartPie());
		$this->addShortcode(new PieChartDoughnut());
		$this->addShortcode(new PieChartWithIcon());
		$this->addShortcode(new Accordion());
		$this->addShortcode(new AccordionTab());
		$this->addShortcode(new BlogList());
		$this->addShortcode(new Button());
		$this->addShortcode(new Blockquote());
		$this->addShortcode(new CustomFont());
		$this->addShortcode(new Highlight());
		$this->addShortcode(new ImageGallery());
		$this->addShortcode(new GoogleMap());
		$this->addShortcode(new Separator());
		$this->addShortcode(new VideoButton());
		$this->addShortcode(new Dropcaps());
		$this->addShortcode(new IconWithText());
		$this->addShortcode(new SocialShare());
		$this->addShortcode(new VideoBanner());
		$this->addShortcode(new AnimationsHolder());
		$this->addShortcode(new SectionTitle());
		$this->addShortcode(new SectionSubtitle());
		$this->addShortcode(new InfoBox());
		$this->addShortcode(new ProcessHolder());
		$this->addShortcode(new ProcessItem());
		$this->addShortcode(new ComparisonPricingTablesHolder());
		$this->addShortcode(new ComparisonPricingTable());
		$this->addShortcode(new VerticalProgressBar());
		$this->addShortcode(new IconProgressBar());
	}

	/**
	 * Calls ShortcodeLoader::addShortcodes and than loops through added shortcodes and calls render method
	 * of each shortcode object
	 */
	public function load() {
		$this->addShortcodes();

		foreach($this->loadedShortcodes as $shortcode) {
			add_shortcode($shortcode->getBase(), array($shortcode, 'render'));
		}

	}
}

$shortcodeLoader = ShortcodeLoader::getInstance();
$shortcodeLoader->load();