require 'spec_helper'

describe "User Pages" do
	

	subject { page }

	describe "signup page" do
		describe "Sign-up page UI validation" do
			before {visit signup_path}
			it {should have_selector('h1', text: 'Sign up') }
			it {should have_selector('title', text: 'Sign up') }
		end
	end

	describe "signup" do
		before {visit signup_path}
		let(:submit) {"Create my account"}


		describe "with invalid information" do
			it "should not create a user" do
				expect {click_button submit}.not_to change(User, :count)
			end

			describe "should return error - all blank" do
				before {click_button submit}
				it {should have_selector('h1', text: 'Sign up') }
				it {should have_selector('title', text: 'Sign up') }
				it {should have_content('error')}
				it {should have_selector('li', text: 'Password can\'t be blank')}
				it {should have_selector('li', text: 'Name can\'t be blank')}
				it {should have_selector('li', text: 'Email can\'t be blank')}
				it {should have_selector('li', text: 'Email is invalid')}
				it {should have_selector('li', text: 'Password is too short (minimum is 6 characters)')}
				it {should have_selector('li', text: 'Password confirmation can\'t be blank')}

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
    describe "profile" do
    	before {visit user_path(user)}

    	it {should have_selector('h1', text: user.name)}
    	it {should have_selector('title', text: user.name)}
    end
end

