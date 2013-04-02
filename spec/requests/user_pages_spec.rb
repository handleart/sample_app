require 'spec_helper'

describe "User Pages" do
	

	subject { page }

	describe "Sign-up" do
		before {visit signup_path}
		let(:submit) {"Create my account"}
		describe "Sign-up page UI validation" do
			it {should have_selector('h1', text: 'Sign up') }
			it {should have_selector('title', text: 'Sign up') }
		end

		describe "with invalid information" do
			it "should not create a user" do
				expect {click_button submit}.not_to change(User, :count)
			end
		end

		describe "with valid information" do
			before do
				fill_in "Name", 	with: "Example User"
				fill_in "Email",	with: "Exampleuser@example.com"
				fill_in "Password",	with: "Password123"
				fill_in "Confirmation", with: "Password123"
			end
			it "should create a user" do
				expect { click_button submit}.to change(User, :count).by(1)
			end
		end
		
	end

 let(:user) {FactoryGirl.create(:user)} 
    describe "Profile page" do
    	before {visit user_path(user)}

    	it {should have_selector('h1', text: user.name)}
    	it {should have_selector('title', text: user.name)}
    end
end

