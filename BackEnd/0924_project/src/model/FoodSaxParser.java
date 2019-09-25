package model;

<<<<<<< Updated upstream
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import java.util.List;
import java.util.Map;


/**
 * FoodNutritionSAXHandler와 FoodSAXHandler를 이용해서 식품 정보를 load하는 SAX Parser 프로 그램
 */
public class FoodSaxParser {
    private String nutritionFilePath = "../res/FoodNutritionInfo.xml";
    private String foodFilePath = "../res/foodInfo.xml";
    private StringBuilder xml;
    private List<Food> foods;

    public FoodSaxParser(String string, String string2) {
        loadData(string, string2);
    }

    /**
     * FoodNutritionSAXHandler와 FoodSAXHandler를 이용 파싱한 식품 정보와 식품 영양 정보를  Food에 병합한다.
     *
     * @param string2
     * @param string
     */
    private void loadData(String string, String string2) {
        SAXParserFactory factory = SAXParserFactory.newInstance();
        try {
            SAXParser parser = factory.newSAXParser();
            FoodSAXHandler handler = new FoodSAXHandler();
            FoodNutritionSAXHandler nHandler = new FoodNutritionSAXHandler();
            parser.parse(string, handler);
            parser.parse(string2, nHandler);
            Map<String, Food> foodMap = handler.getFoods();
            foods = nHandler.getList();
            Food find;
            for (Food food : foods) {
                find = foodMap.get(food.getName());
                if (find != null) {
                    food.setCode(find.getCode());
                    food.setName(find.getName());
                    food.setMaker(find.getMaker());
                    food.setMaterial(find.getMaterial());
                    food.setImg(find.getImg());
                }
            }
//			System.out.println(foods);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public List<Food> getFoods() {
        return foods;
    }

    public void setFoods(List<Food> foods) {
        this.foods = foods;
    }

=======
import java.util.List;
import java.util.Map;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;


/**
 * FoodNutritionSAXHandler와 FoodSAXHandler를 이용해서 식품 정보를 load하는 SAX Parser 프로 그램  
 *
 */
public class FoodSaxParser {
	private String nutritionFilePath = "./res/FoodNutritionInfo.xml";
	private String foodFilePath = "./res/foodInfo.xml";
	private StringBuilder xml ;
	private List<Food> foods;
 	public FoodSaxParser(String string, String string2) {
		loadData(string,string2);
	}
 	
 	/**
 	 * FoodNutritionSAXHandler와 FoodSAXHandler를 이용 파싱한 식품 정보와 식품 영양 정보를  Food에 병합한다. 
 	 * @param string2 
 	 * @param string 
 	 */
	private void loadData(String string, String string2) {
		SAXParserFactory factory = SAXParserFactory.newInstance();
		try{
			SAXParser parser = factory.newSAXParser();
			FoodSAXHandler handler = new FoodSAXHandler();
			FoodNutritionSAXHandler nHandler = new FoodNutritionSAXHandler();
			parser.parse(string,handler);
			parser.parse(string2,nHandler);
			Map<String, Food> foodMap = handler.getFoods();
			foods = nHandler.getList();
			Food find;
			for (Food food : foods) {
				find = foodMap.get(food.getName());
				if(find!=null) {
					food.setCode(find.getCode());
					food.setName(find.getName());
					food.setMaker(find.getMaker());
					food.setMaterial(find.getMaterial());
					food.setImg(find.getImg());
				}
			}
//			System.out.println(foods);
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	public List<Food> getFoods() {
		return foods;
	}
	public void setFoods(List<Food> foods) {
		this.foods = foods;
	}
	
>>>>>>> Stashed changes
}
